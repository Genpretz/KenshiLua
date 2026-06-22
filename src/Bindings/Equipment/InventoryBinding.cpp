#include "pch.h"
#include "Bindings/Equipment/InventoryBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/Core/RootObjectBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Inventory.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

// ----------------------------------
// InventoryBinding
// ----------------------------------

    static Inventory* getInv(lua_State* L, int idx)
    {
        return checkObject<Inventory>(L, idx, InventoryBinding::getMetatableName());
    }


    int InventoryBinding::gc(lua_State* L) { return noopGc(L); }

    int InventoryBinding::tostring(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        return genericTostringPtr(L, "%s", inv);
    }

    int InventoryBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, InventoryBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        Inventory* inv = getInv(L, 1);
        if (!inv) { lua_pushnil(L); return 1; }

        // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __index type from header line 156
        if (strcmp(key, "hasRoomCache") == 0) { lua_pushinteger(L, (lua_Integer)inv->hasRoomCache); return 1; }
        // TODO lektor<Item*> _allItems; unsupported __index type from header line 232
        // TODO boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > sections; unsupported __index type from header line 233
        // TODO lektor<InventorySection*> sectionsInSearchOrder; unsupported __index type from header line 234
        if (strcmp(key, "callbackObject") == 0) { return RootObjectBinding::pushRootObject(L, inv->callbackObject); }
        if (strcmp(key, "owner") == 0) { return RootObjectBinding::pushRootObject(L, inv->owner); }
        if (strcmp(key, "totalWeight") == 0) { lua_pushnumber(L, inv->totalWeight); return 1; }

        lua_pushnil(L);
        return 1;
    }

    int InventoryBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __newindex type from header line 156
        // TODO Inventory::HasRoomCache* hasRoomCache; unsupported __newindex type from header line 169
        // TODO lektor<Item*> _allItems; unsupported __newindex type from header line 232
        // TODO boost::unordered::unordered_map<std::string, InventorySection*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, InventorySection*>, Ogre::GeneralAllocPolicy > > sections; unsupported __newindex type from header line 233
        // TODO lektor<InventorySection*> sectionsInSearchOrder; unsupported __newindex type from header line 234
        // TODO RootObject* callbackObject; unsupported __newindex type from header line 235
        // TODO RootObject* owner; unsupported __newindex type from header line 236
        if (strcmp(key, "totalWeight") == 0) { inv->totalWeight = (float)luaL_checknumber(L, 3); return 0; }

        return luaL_error(L, "unknown or read-only field '%s'", key);
    }

    int InventoryBinding::_DESTRUCTOR(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->_DESTRUCTOR();
        return 0;
    }

    int InventoryBinding::clearAll(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool destroy = lua_toboolean(L, 2) != 0;
        bool skipUnique = lua_toboolean(L, 3) != 0;
        inv->clearAll(destroy, skipUnique);
        return 0;
    }

    int InventoryBinding::notifyModified(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->notifyModified();
        return 0;
    }

    int InventoryBinding::removeAllSections(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->removeAllSections();
        return 0;
    }

    int InventoryBinding::getSection(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        std::string name = luaL_checkstring(L, 2);
        InventorySection* result = inv->getSection(name);
        return pushObject<InventorySection>(L, result, InventorySectionBinding::getMetatableName());
    }

    int InventoryBinding::getCallbackCharacter(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Character* result = inv->getCallbackCharacter();
        return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
    }

    int InventoryBinding::hasItemType(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        itemType item = (itemType)luaL_checkinteger(L, 2);
        bool skipEquipped = lua_toboolean(L, 3) != 0;
        bool result = inv->hasItemType(item, skipEquipped);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::hasStolenItems(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->hasStolenItems();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::getSecondaryWeapon(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Weapon* result = inv->getSecondaryWeapon();
        return ItemBinding::pushItem(L, (Item*)result);
    }

    int InventoryBinding::getPrimaryWeapon(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        Weapon* result = inv->getPrimaryWeapon();
        return ItemBinding::pushItem(L, (Item*)result);
    }


    int InventoryBinding::hasWeaponEquipped(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->hasWeaponEquipped();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::isAContainer(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isAContainer();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::getOwner(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        RootObject* result = inv->getOwner();
        return RootObjectBinding::pushRootObject(L, result);
    }

    int InventoryBinding::isEmpty(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isEmpty();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::recalculateTotalWeight(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->recalculateTotalWeight();
        return 0;
    }

    int InventoryBinding::getTotalWeight(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        float result = inv->getTotalWeight();
        lua_pushnumber(L, result);
        return 1;
    }

    int InventoryBinding::getMoney(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        int result = inv->getMoney();
        lua_pushinteger(L, result);
        return 1;
    }

    int InventoryBinding::takeMoney(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        int val = (int)luaL_checkinteger(L, 2);
        inv->takeMoney(val);
        return 0;
    }

    int InventoryBinding::isVisible(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        bool result = inv->isVisible();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventoryBinding::refreshGui(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->refreshGui();
        return 0;
    }

    int InventoryBinding::_NV_refreshGui(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->_NV_refreshGui();
        return 0;
    }

    int InventoryBinding::autoArrange(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        inv->autoArrange();
        return 0;
    }

    int InventoryBinding::getCallbackObject(lua_State* L)
    {
        Inventory* inv = getInv(L, 1);
        if (!inv) return luaL_error(L, "Inventory is nil");

        RootObject* result = inv->getCallbackObject();
        return RootObjectBinding::pushRootObject(L, result);
    }


    /*
    Skipped methods needing manual binding:
    line 125: Inventory* _CONSTRUCTOR(...) - unsupported arg type
    line 128: const hand& getHandle(...) - reference return type
    line 130: GameData* serialise(...) - unsupported arg type
    line 131: void loadFrom(...) - overloaded method
    line 132: void loadFrom(...) - overloaded method
    line 134: void fillFromVendorList(...) - overloaded method
    line 135: void fillFromVendorList(...) - overloaded method
    line 136: InventorySection* initialiseNewSection(...) - unsupported arg type
    line 137: InventorySection* _NV_initialiseNewSection(...) - unsupported arg type
    line 138: void resizeSection(...) - unsupported arg type
    line 141: InventorySection* getSectionOfType(...) - unsupported arg type
    line 142: void getAllSectionsOfType(...) - unsupported arg type
    line 143: lektor<InventorySection*>& getAllSections(...) - reference return type
    line 144: bool getExcessLoot(...) - unsupported arg type
    line 145: void getResourceItems(...) - unsupported arg type
    line 146: int getNumItems(...) - overloaded method
    line 147: int getNumItems(...) - overloaded method
    line 149: bool addItem(...) - unsupported arg type
    line 150: bool _NV_addItem(...) - unsupported arg type
    line 151: bool tryAddItem(...) - unsupported arg type
    line 152: bool _NV_tryAddItem(...) - unsupported arg type
    line 170: bool hasRoomForItem(...) - unsupported arg type
    line 171: bool _NV_hasRoomForItem(...) - unsupported arg type
    line 172: Item* removeItemDontDestroy_returnsItem(...) - unsupported arg type
    line 173: Item* _NV_removeItemDontDestroy_returnsItem(...) - unsupported arg type
    line 174: bool removeItemAutoDestroy(...) - unsupported arg type
    line 175: bool _NV_removeItemAutoDestroy(...) - unsupported arg type
    line 176: void dropItem(...) - unsupported arg type
    line 177: void _NV_dropItem(...) - unsupported arg type
    line 178: bool transferMouseItem(...) - unsupported arg type
    line 179: bool hasItem(...) - overloaded method
    line 180: bool hasItem(...) - overloaded method
    line 181: int countItems(...) - unsupported arg type
    line 182: Item* getItem(...) - unsupported arg type
    line 184: void getAllStolenItems(...) - unsupported arg type
    line 186: void getAllItemsOfType(...) - unsupported arg type
    line 187: void getEquippedWeapons(...) - unsupported arg type
    line 190: void getEquippedArmour(...) - unsupported arg type
    line 191: Item* takeOneItemOnly(...) - unsupported arg type
    line 192: bool deathCheck(...) - unsupported arg type
    line 193: bool takeItem_EntireStack(...) - overloaded method
    line 194: Item* takeItem_EntireStack(...) - overloaded method
    line 195: bool hasItemFunction(...) - unsupported arg type
    line 196: void getAllItemsWithFunction(...) - unsupported arg type
    line 197: Item* getBestItemWithFunction(...) - unsupported arg type
    line 198: Item* getBestItemWithLowestCharges(...) - overloaded method
    line 199: Item* getBestItemWithLowestCharges(...) - overloaded method
    line 200: Item* getBestFoodItem(...) - unsupported arg type
    line 201: int getNumFoodItems(...) - unsupported arg type
    line 202: Item* _getBestFoodItem(...) - unsupported arg type
    line 203: int _getNumFoodItems(...) - unsupported arg type
    line 205: bool equipItem(...) - unsupported arg type
    line 214: Item* buyItem(...) - unsupported arg type
    line 215: InventoryGUI* getInventoryGUI(...) - unsupported return type
    line 217: void _sectionAddItemCallback(...) - unsupported arg type
    line 218: void _NV__sectionAddItemCallback(...) - unsupported arg type
    line 219: void _sectionUpdateItemCallback(...) - unsupported arg type
    line 220: void _NV__sectionUpdateItemCallback(...) - unsupported arg type
    line 221: void _sectionRemoveItemCallback(...) - unsupported arg type
    line 222: void _NV__sectionRemoveItemCallback(...) - unsupported arg type
    line 227: const lektor<Item*>& getAllItems(...) - reference return type
    line 228: void _addToList(...) - unsupported arg type
    line 229: void _NV__addToList(...) - unsupported arg type
    line 230: void _removeFromList(...) - unsupported arg type
    line 231: void _NV__removeFromList(...) - unsupported arg type
    */

    void InventoryBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       InventoryBinding::gc },
            { "__tostring", InventoryBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "_DESTRUCTOR", InventoryBinding::_DESTRUCTOR },
            { "clearAll", InventoryBinding::clearAll },
            { "notifyModified", InventoryBinding::notifyModified },
            { "removeAllSections", InventoryBinding::removeAllSections },
            { "getSection", InventoryBinding::getSection },
            { "getCallbackCharacter", InventoryBinding::getCallbackCharacter },
            { "hasItemType", InventoryBinding::hasItemType },
            { "hasStolenItems", InventoryBinding::hasStolenItems },
            { "getSecondaryWeapon", InventoryBinding::getSecondaryWeapon },
            { "getPrimaryWeapon", InventoryBinding::getPrimaryWeapon },
            { "hasWeaponEquipped", InventoryBinding::hasWeaponEquipped },
            { "isAContainer", InventoryBinding::isAContainer },
            { "getOwner", InventoryBinding::getOwner },
            { "isEmpty", InventoryBinding::isEmpty },
            { "recalculateTotalWeight", InventoryBinding::recalculateTotalWeight },
            { "getTotalWeight", InventoryBinding::getTotalWeight },
            { "getMoney", InventoryBinding::getMoney },
            { "takeMoney", InventoryBinding::takeMoney },
            { "isVisible", InventoryBinding::isVisible },
            { "refreshGui", InventoryBinding::refreshGui },
            { "_NV_refreshGui", InventoryBinding::_NV_refreshGui },
            { "autoArrange", InventoryBinding::autoArrange },
            { "getCallbackObject", InventoryBinding::getCallbackObject },
            { 0, 0 }
        };

        registerClass(L, InventoryBinding::getMetatableName(),
            meta, methods,
            InventoryBinding::index,
            InventoryBinding::newindex);
    }

// ----------------------------------
// InventorySectionBinding
// ----------------------------------

    static InventorySection* getIS(lua_State* L, int idx)
    {
        return checkObject<InventorySection>(L, idx, InventorySectionBinding::getMetatableName());
    }

    int InventorySectionBinding::gc(lua_State* L) { return noopGc(L); }

    int InventorySectionBinding::tostring(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int InventorySectionBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, InventorySectionBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        InventorySection* s = getIS(L, 1);
        if (!s) { lua_pushnil(L); return 1; }

        if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
        if (strcmp(key, "width") == 0) { lua_pushinteger(L, s->width); return 1; }
        if (strcmp(key, "height") == 0) { lua_pushinteger(L, s->height); return 1; }
        if (strcmp(key, "armourOnly") == 0) { lua_pushboolean(L, s->armourOnly ? 1 : 0); return 1; }
        // TODO Ogre::vector<InventorySection::SectionItem>::type items; unsupported __index type from header line 94
        // TODO Array2d<Item> content; unsupported __index type from header line 95
        if (strcmp(key, "stackingBonusMin") == 0) { lua_pushinteger(L, s->stackingBonusMin); return 1; }
        if (strcmp(key, "stackingBonusMult") == 0) { lua_pushnumber(L, s->stackingBonusMult); return 1; }
        // TODO lektor<GameData*> veryLimitedSlot; unsupported __index type from header line 98
        if (strcmp(key, "itemsLimit") == 0) { lua_pushinteger(L, s->itemsLimit); return 1; }
        if (strcmp(key, "weightMultiplier") == 0) { lua_pushnumber(L, s->weightMultiplier); return 1; }
        if (strcmp(key, "totalWeight") == 0) { lua_pushnumber(L, s->totalWeight); return 1; }
        if (strcmp(key, "isAnEquippedItemSection") == 0) { lua_pushboolean(L, s->isAnEquippedItemSection ? 1 : 0); return 1; }
        if (strcmp(key, "limitedSlot") == 0) { lua_pushinteger(L, s->limitedSlot); return 1;}
        if (strcmp(key, "containerSlot") == 0) { lua_pushboolean(L, s->containerSlot ? 1 : 0); return 1; }

        // --- unique objects ---
        if (strcmp(key, "callbackObject") == 0) { 
            if (s->callbackObject) return RootObjectBinding::pushRootObject(L, s->callbackObject); else lua_pushnil(L); return 1;
        }
        if (strcmp(key, "parentInventory") == 0) {
            if (s->parentInventory) return pushObject<Inventory>(L, s->parentInventory, InventoryBinding::getMetatableName());
            lua_pushnil(L); return 1;
        }
        if (strcmp(key, "enabled") == 0) { lua_pushboolean(L, s->enabled ? 1 : 0); return 1; }

        lua_pushnil(L);
        return 1;
    }

    int InventorySectionBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }
        if (strcmp(key, "width") == 0) { s->width = (int)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "height") == 0) { s->height = (int)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "armourOnly") == 0) { s->armourOnly = lua_toboolean(L, 3) != 0; return 0; }
        // TODO Ogre::vector<InventorySection::SectionItem>::type items; unsupported __newindex type from header line 94
        // TODO Array2d<Item> content; unsupported __newindex type from header line 95
        if (strcmp(key, "stackingBonusMin") == 0) { s->stackingBonusMin = (int)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "stackingBonusMult") == 0) { s->stackingBonusMult = (float)luaL_checknumber(L, 3); return 0; }
        // TODO lektor<GameData*> veryLimitedSlot; unsupported __newindex type from header line 98
        if (strcmp(key, "itemsLimit") == 0) { s->itemsLimit = (int)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "weightMultiplier") == 0) { s->weightMultiplier = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "totalWeight") == 0) { s->totalWeight = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "isAnEquippedItemSection") == 0) { s->isAnEquippedItemSection = lua_toboolean(L, 3) != 0; return 0; }
        // TODO AttachSlot limitedSlot; unsupported __newindex type from header line 103
        if (strcmp(key, "containerSlot") == 0) { s->containerSlot = lua_toboolean(L, 3) != 0; return 0; }
        // TODO RootObject* callbackObject; unsupported __newindex type from header line 105
        // TODO Inventory* parentInventory; unsupported __newindex type from header line 106
        if (strcmp(key, "enabled") == 0) { s->enabled = lua_toboolean(L, 3) != 0; return 0; }

        return luaL_error(L, "unknown or read-only field '%s'", key);
    }

    int InventorySectionBinding::_DESTRUCTOR(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->_DESTRUCTOR();
        return 0;
    }

    int InventorySectionBinding::notifyModified(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->notifyModified();
        return 0;
    }

    int InventorySectionBinding::getItemAt(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int x = (int)luaL_checkinteger(L, 2);
        int y = (int)luaL_checkinteger(L, 3);
        Item* result = s->getItemAt(x, y);
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    int InventorySectionBinding::hasItemType(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        itemType type = (itemType)luaL_checkinteger(L, 2);
        bool result = s->hasItemType(type);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::autoArrange(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->autoArrange();
        return 0;
    }

    int InventorySectionBinding::_NV_autoArrange(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->_NV_autoArrange();
        return 0;
    }

    int InventorySectionBinding::getNumItems(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        unsigned int result = s->getNumItems();
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::isEmpty(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->isEmpty();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::clearAllItems(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool destroy = lua_toboolean(L, 2) != 0;
        bool skipUnique = lua_toboolean(L, 3) != 0;
        s->clearAllItems(destroy, skipUnique);
        return 0;
    }

    int InventorySectionBinding::applyStackingBonuses(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int normalStackableAmount = (int)luaL_checkinteger(L, 2);
        int result = s->applyStackingBonuses(normalStackableAmount);
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::recalculateTotalWeight(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->recalculateTotalWeight();
        return 0;
    }

    int InventorySectionBinding::setWeightMultiplier(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        float mult = (float)luaL_checknumber(L, 2);
        s->setWeightMultiplier(mult);
        return 0;
    }

    int InventorySectionBinding::setStackingBonus(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int minn = (int)luaL_checkinteger(L, 2);
        float mult = (float)luaL_checknumber(L, 3);
        s->setStackingBonus(minn, mult);
        return 0;
    }

    int InventorySectionBinding::getMaxStack(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int result = s->getMaxStack();
        lua_pushinteger(L, result);
        return 1;
    }

    int InventorySectionBinding::clearVeryLimitedSlot(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        s->clearVeryLimitedSlot();
        return 0;
    }

    int InventorySectionBinding::getEnabled(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->getEnabled();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::setEnabled(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool value = lua_toboolean(L, 2) != 0;
        s->setEnabled(value);
        return 0;
    }

    int InventorySectionBinding::setItemsLimitCount(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int value = (int)luaL_checkinteger(L, 2);
        s->setItemsLimitCount(value);
        return 0;
    }

    int InventorySectionBinding::getItemsLimitReached(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        bool result = s->getItemsLimitReached();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int InventorySectionBinding::getInventory(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        Inventory* result = s->getInventory();
        return pushObject<Inventory>(L, result, InventoryBinding::getMetatableName());
    }

    int InventorySectionBinding::getFillPercentage(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        float result = s->getFillPercentage();
        lua_pushnumber(L, result);
        return 1;
    }

    int InventorySectionBinding::getItem(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        Item* result = s->getItem();
        return pushObject<Item>(L, result, ItemBinding::getMetatableName());
    }

    int InventorySectionBinding::resize(lua_State* L)
    {
        InventorySection* s = getIS(L, 1);
        if (!s) return luaL_error(L, "InventorySection is nil");

        int w = (int)luaL_checkinteger(L, 2);
        int h = (int)luaL_checkinteger(L, 3);
        bool clearContent = lua_toboolean(L, 4) != 0;
        s->resize(w, h, clearContent);
        return 0;
    }

    /*
    Skipped methods needing manual binding:
    line 34: InventorySection* _CONSTRUCTOR(...) - unsupported arg type
    line 37: bool hasRoomForItem(...) - unsupported arg type
    line 38: bool _NV_hasRoomForItem(...) - unsupported arg type
    line 40: bool addItem(...) - unsupported arg type
    line 41: bool _NV_addItem(...) - unsupported arg type
    line 42: void _addItem(...) - unsupported arg type
    line 43: void _NV__addItem(...) - unsupported arg type
    line 46: bool hasItem(...) - overloaded method
    line 47: bool hasItem(...) - overloaded method
    line 51: void getAllItemsOfType(...) - overloaded method
    line 52: void getAllItemsOfType(...) - overloaded method
    line 53: void getAllItemsOfName(...) - unsupported arg type
    line 56: bool removeItem(...) - unsupported arg type
    line 58: bool canItemGoHere(...) - unsupported arg type
    line 59: bool getValidInventoryPosition(...) - unsupported arg type
    line 60: bool findNearestPlaceForItem(...) - unsupported arg type
    line 61: int getItemsInFootprint(...) - overloaded method
    line 62: int getItemsInFootprint(...) - overloaded method
    line 63: bool existsItemInFootprint(...) - unsupported arg type
    line 64: AttachSlot getLimitedSlot(...) - unsupported return type
    line 65: void setupContainerData(...) - unsupported arg type
    line 72: void addVeryLimitedSlot(...) - unsupported arg type
    line 74: const lektor<GameData*>& getVeryLimitedSlot(...) - reference return type
    line 75: bool isLimitedSlotCompatible(...) - overloaded method
    line 76: bool isLimitedSlotCompatible(...) - overloaded method
    line 85: const Ogre::vector<InventorySection::SectionItem>::type& getItems(...) - reference return type
    line 91: void setupEquipCallbacks(...) - unsupported arg type
    line 92: int numItemsInFootprint(...) - unsupported arg type
    */


    void InventorySectionBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       InventorySectionBinding::gc },
            { "__tostring", InventorySectionBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "_DESTRUCTOR", InventorySectionBinding::_DESTRUCTOR },
            { "notifyModified", InventorySectionBinding::notifyModified },
            { "getItemAt", InventorySectionBinding::getItemAt },
            { "hasItemType", InventorySectionBinding::hasItemType },
            { "autoArrange", InventorySectionBinding::autoArrange },
            { "_NV_autoArrange", InventorySectionBinding::_NV_autoArrange },
            { "getNumItems", InventorySectionBinding::getNumItems },
            { "isEmpty", InventorySectionBinding::isEmpty },
            { "clearAllItems", InventorySectionBinding::clearAllItems },
            { "applyStackingBonuses", InventorySectionBinding::applyStackingBonuses },
            { "recalculateTotalWeight", InventorySectionBinding::recalculateTotalWeight },
            { "setWeightMultiplier", InventorySectionBinding::setWeightMultiplier },
            { "setStackingBonus", InventorySectionBinding::setStackingBonus },
            { "getMaxStack", InventorySectionBinding::getMaxStack },
            { "clearVeryLimitedSlot", InventorySectionBinding::clearVeryLimitedSlot },
            { "getEnabled", InventorySectionBinding::getEnabled },
            { "setEnabled", InventorySectionBinding::setEnabled },
            { "setItemsLimitCount", InventorySectionBinding::setItemsLimitCount },
            { "getItemsLimitReached", InventorySectionBinding::getItemsLimitReached },
            { "getInventory", InventorySectionBinding::getInventory },
            { "getFillPercentage", InventorySectionBinding::getFillPercentage },
            { "getItem", InventorySectionBinding::getItem },
            { "resize", InventorySectionBinding::resize },
            { 0, 0 }
        };

        // Pass index/newindex as C functions so that dot-access to raw member
        // fields (e.g. inv.totalWeight) works alongside method call syntax.
        registerClass(L, InventorySectionBinding::getMetatableName(),
            meta, methods,
            InventorySectionBinding::index,
            InventorySectionBinding::newindex);
    }

// ---------------------------------
// SectionItemBinding
// ---------------------------------
    
    static InventorySection::SectionItem* getSecItem(lua_State* L, int idx)
    {
        return checkObject<InventorySection::SectionItem>(L, idx, SectionItemBinding::getMetatableName());
    }

    int SectionItemBinding::gc(lua_State* L) { return noopGc(L); }

    int SectionItemBinding::tostring(lua_State* L)
    {
        InventorySection::SectionItem* s = getSecItem(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int SectionItemBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, SectionItemBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        InventorySection::SectionItem* s = getSecItem(L, 1);
        if (!s) { lua_pushnil(L); return 1; }

        if (strcmp(key, "item") == 0) { return ItemBinding::pushItem(L, s->item); }
        if (strcmp(key, "x") == 0) { lua_pushinteger(L, s->x); return 1; }
        if (strcmp(key, "y") == 0) { lua_pushinteger(L, s->y); return 1; }
        if (strcmp(key, "w") == 0) { lua_pushinteger(L, s->w); return 1; }
        if (strcmp(key, "h") == 0) { lua_pushinteger(L, s->h); return 1; }

        lua_pushnil(L);
        return 1;
    }

    int SectionItemBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        InventorySection::SectionItem* s = getSecItem(L, 1);
        if (!s) return luaL_error(L, "SectionItem is nil");

        if (strcmp(key, "item") == 0) { s->item = ItemBinding::checkItem(L, 3); return 0; }
        if (strcmp(key, "x") == 0) { s->x = (unsigned short)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "y") == 0) { s->y = (unsigned short)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "w") == 0) { s->w = (unsigned short)luaL_checkinteger(L, 3); return 0; }
        if (strcmp(key, "h") == 0) { s->h = (unsigned short)luaL_checkinteger(L, 3); return 0; }

        return luaL_error(L, "unknown or read-only field '%s'", key);
    }

    void SectionItemBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       SectionItemBinding::gc },
            { "__tostring", SectionItemBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { 0, 0 }
        };
        registerClass(L, SectionItemBinding::getMetatableName(), meta, methods, SectionItemBinding::index, SectionItemBinding::newindex);
    }

    // ----------------------------------
    // HasRoomCacheBinding
    // ----------------------------------
    
    static Inventory::HasRoomCache* getHRC(lua_State* L, int idx)
{
    return checkObject<Inventory::HasRoomCache>(L, idx, HasRoomCacheBinding::getMetatableName());
}

int HasRoomCacheBinding::gc(lua_State* L) { return noopGc(L); }

int HasRoomCacheBinding::tostring(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    return genericTostringPtr(L, "%s", hrc);
}

int HasRoomCacheBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, HasRoomCacheBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) { lua_pushnil(L); return 1; }

    // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __index type from header line 156

    lua_pushnil(L);
    return 1;
}

int HasRoomCacheBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    // TODO std::map<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData*const, bool> > > itemStates; unsupported __newindex type from header line 156

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int HasRoomCacheBinding::modified(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    hrc->modified();
    return 0;
}

int HasRoomCacheBinding::_DESTRUCTOR(lua_State* L)
{
    Inventory::HasRoomCache* hrc = getHRC(L, 1);
    if (!hrc) return luaL_error(L, "HasRoomCache is nil");

    hrc->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 158: bool knowsAbout(...) - unsupported arg type
  line 159: bool hasRoomFor(...) - unsupported arg type
  line 160: void remember(...) - unsupported arg type
  line 163: HasRoomCache* _CONSTRUCTOR(...) - unsupported return type
*/

void HasRoomCacheBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HasRoomCacheBinding::gc },
        { "__tostring", HasRoomCacheBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "modified", HasRoomCacheBinding::modified },
        { "_DESTRUCTOR", HasRoomCacheBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, HasRoomCacheBinding::getMetatableName(), meta, methods, HasRoomCacheBinding::index, HasRoomCacheBinding::newindex);
}

} // namespace KenshiLua