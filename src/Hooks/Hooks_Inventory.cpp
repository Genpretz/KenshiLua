#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Inventory.h / InventoryItemBase.h
// ---------------------------------------------------------------------------

static InventorySection* (*Inventory_getSectionOfType_orig)(Inventory*, int) = NULL;
static InventorySection* Inventory_getSectionOfType_hook(Inventory* thisptr, int type)
{
    InventorySection* current = Inventory_getSectionOfType_orig(thisptr, type);
    InventorySection* overrideSection = CallInventoryGetSectionOfTypeCallbacks(thisptr, type);
    return overrideSection ? overrideSection : current;
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_getSectionOfType,
    "Inventory::getSectionOfType",
    KenshiLib::GetRealAddress(&Inventory::getSectionOfType),
    Inventory_getSectionOfType_hook, Inventory_getSectionOfType_orig)

static Item* (*Inventory_getBestFoodItem_orig)(const Inventory*, Character*) = NULL;
static Item* Inventory_getBestFoodItem_hook(const Inventory* thisptr, Character* race)
{
    Item* current = Inventory_getBestFoodItem_orig(thisptr, race);
    Item* overrideFood = CallInventoryGetBestFoodItemCallbacks(const_cast<Inventory*>(thisptr), race);
    return overrideFood ? overrideFood : current;
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_getBestFoodItem,
    "Inventory::getBestFoodItem",
    KenshiLib::GetRealAddress(&Inventory::getBestFoodItem),
    Inventory_getBestFoodItem_hook, Inventory_getBestFoodItem_orig)

static int (*InventoryItemBase_getValueSingle_orig)(const InventoryItemBase*, bool) = NULL;
static int InventoryItemBase_getValueSingle_hook(const InventoryItemBase* thisptr, bool isPlayer)
{
    int current = InventoryItemBase_getValueSingle_orig(thisptr, isPlayer);
    return CallInventoryItemBaseGetValueSingleCallbacks(thisptr, isPlayer, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryItemBase_getValueSingle,
    "InventoryItemBase::getValueSingle",
    KenshiLib::GetRealAddress(&InventoryItemBase::_NV_getValueSingle),
    InventoryItemBase_getValueSingle_hook, InventoryItemBase_getValueSingle_orig)

static bool (*Inventory_NV_addItem_orig)(Inventory*, Item*, int, bool, bool) = NULL;
static bool Inventory_NV_addItem_hook(Inventory* thisptr, Item* item, int quantity, bool dropOnFail, bool destroyOnFail)
{
    if (!CallInventoryAddItemCallbacks(thisptr, item, quantity, dropOnFail, destroyOnFail))
        return false;
    return Inventory_NV_addItem_orig(thisptr, item, quantity, dropOnFail, destroyOnFail);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_addItem,
    "Inventory::_NV_addItem",
    KenshiLib::GetRealAddress(static_cast<bool (Inventory::*)(Item*, int, bool, bool)>(&Inventory::_NV_addItem)),
    Inventory_NV_addItem_hook, Inventory_NV_addItem_orig)

static Item* (*Inventory_NV_removeItemDontDestroy_returnsItem_orig)(Inventory*, Item*, int, bool) = NULL;
static Item* Inventory_NV_removeItemDontDestroy_returnsItem_hook(Inventory* thisptr, Item* it, int howmany, bool returnCopyIfSomeLeft)
{
    Item* current = Inventory_NV_removeItemDontDestroy_returnsItem_orig(thisptr, it, howmany, returnCopyIfSomeLeft);
    Item* overrideItem = CallInventoryRemoveItemCallbacks(thisptr, it, howmany, returnCopyIfSomeLeft);
    return overrideItem ? overrideItem : current;
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_removeItemDontDestroy_returnsItem,
    "Inventory::_NV_removeItemDontDestroy_returnsItem",
    KenshiLib::GetRealAddress(static_cast<Item* (Inventory::*)(Item*, int, bool)>(&Inventory::_NV_removeItemDontDestroy_returnsItem)),
    Inventory_NV_removeItemDontDestroy_returnsItem_hook, Inventory_NV_removeItemDontDestroy_returnsItem_orig)

static Item* (*Inventory_buyItem_orig)(Inventory*, Item*, RootObject*) = NULL;
static Item* Inventory_buyItem_hook(Inventory* thisptr, Item* itemToBuy, RootObject* sendingTo)
{
    Item* current = Inventory_buyItem_orig(thisptr, itemToBuy, sendingTo);
    Item* overrideItem = CallInventoryBuyItemCallbacks(thisptr, itemToBuy, sendingTo);
    return overrideItem ? overrideItem : current;
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_buyItem,
    "Inventory::buyItem",
    KenshiLib::GetRealAddress(&Inventory::buyItem),
    Inventory_buyItem_hook, Inventory_buyItem_orig)

static void (*Inventory_NV_sectionAddItemCallback_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_sectionAddItemCallback_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_sectionAddItemCallback_orig(thisptr, item);
    CallInventorySectionAddItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionAddItemCallback,
    "Inventory::_NV__sectionAddItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionAddItemCallback),
    Inventory_NV_sectionAddItemCallback_hook, Inventory_NV_sectionAddItemCallback_orig)

static void (*Inventory_NV_sectionRemoveItemCallback_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_sectionRemoveItemCallback_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_sectionRemoveItemCallback_orig(thisptr, item);
    CallInventorySectionRemoveItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionRemoveItemCallback,
    "Inventory::_NV__sectionRemoveItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionRemoveItemCallback),
    Inventory_NV_sectionRemoveItemCallback_hook, Inventory_NV_sectionRemoveItemCallback_orig)

static void (*Inventory_NV_sectionUpdateItemCallback_orig)(Inventory*, Item*, int) = NULL;
static void Inventory_NV_sectionUpdateItemCallback_hook(Inventory* thisptr, Item* item, int prevQuantity)
{
    Inventory_NV_sectionUpdateItemCallback_orig(thisptr, item, prevQuantity);
    CallInventorySectionUpdateItemCallbacks(thisptr, item, prevQuantity);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_sectionUpdateItemCallback,
    "Inventory::_NV__sectionUpdateItemCallback",
    KenshiLib::GetRealAddress(&Inventory::_NV__sectionUpdateItemCallback),
    Inventory_NV_sectionUpdateItemCallback_hook, Inventory_NV_sectionUpdateItemCallback_orig)

static void (*Inventory_NV_dropItem_orig)(Inventory*, Item*) = NULL;
static void Inventory_NV_dropItem_hook(Inventory* thisptr, Item* item)
{
    Inventory_NV_dropItem_orig(thisptr, item);
    CallInventoryDropItemCallbacks(thisptr, item);
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_NV_dropItem,
    "Inventory::_NV_dropItem",
    KenshiLib::GetRealAddress(&Inventory::_NV_dropItem),
    Inventory_NV_dropItem_hook, Inventory_NV_dropItem_orig)

static Gear* (*Gear_CONSTRUCTOR_orig)(Gear*, GameData*, GameData*, GameData*, hand, int, Faction*) = NULL;
static Gear* Gear_CONSTRUCTOR_hook(Gear* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level, Faction* uniform)
{
    Gear* res = Gear_CONSTRUCTOR_orig(thisptr, baseData, companyData, materialData, _handle, _level, uniform);
    Gear* overrideRes = CallGearConstructedCallbacks(thisptr, baseData, companyData, materialData, _handle, _level, uniform, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Gear_CONSTRUCTOR,
    "Gear::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Gear::_CONSTRUCTOR),
    Gear_CONSTRUCTOR_hook, Gear_CONSTRUCTOR_orig)

static Sword* (*Sword_CONSTRUCTOR_orig)(Sword*, GameData*, GameData*, GameData*, hand, int) = NULL;
static Sword* Sword_CONSTRUCTOR_hook(Sword* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level)
{
    Sword* res = Sword_CONSTRUCTOR_orig(thisptr, baseData, companyData, materialData, _handle, _level);
    Sword* overrideRes = CallSwordConstructedCallbacks(thisptr, baseData, companyData, materialData, _handle, _level, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Sword_CONSTRUCTOR,
    "Sword::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Sword::_CONSTRUCTOR),
    Sword_CONSTRUCTOR_hook, Sword_CONSTRUCTOR_orig)

static Crossbow* (*Crossbow_CONSTRUCTOR_orig)(Crossbow*, GameData*, hand, int) = NULL;
static Crossbow* Crossbow_CONSTRUCTOR_hook(Crossbow* thisptr, GameData* baseData, hand _handle, int _overalllevel)
{
    Crossbow* res = Crossbow_CONSTRUCTOR_orig(thisptr, baseData, _handle, _overalllevel);
    Crossbow* overrideRes = CallCrossbowConstructedCallbacks(thisptr, baseData, _handle, _overalllevel, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Crossbow_CONSTRUCTOR,
    "Crossbow::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Crossbow::_CONSTRUCTOR),
    Crossbow_CONSTRUCTOR_hook, Crossbow_CONSTRUCTOR_orig)

static Armour* (*Armour_CONSTRUCTOR_orig)(Armour*, GameData*, GameData*, hand, Faction*, int) = NULL;
static Armour* Armour_CONSTRUCTOR_hook(Armour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level)
{
    Armour* res = Armour_CONSTRUCTOR_orig(thisptr, baseData, _materialData, _handle, _uniformFlag, _level);
    Armour* overrideRes = CallArmourConstructedCallbacks(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Armour_CONSTRUCTOR,
    "Armour::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Armour::_CONSTRUCTOR),
    Armour_CONSTRUCTOR_hook, Armour_CONSTRUCTOR_orig)

static LockedArmour* (*LockedArmour_CONSTRUCTOR_orig)(LockedArmour*, GameData*, GameData*, hand, Faction*, int) = NULL;
static LockedArmour* LockedArmour_CONSTRUCTOR_hook(LockedArmour* thisptr, GameData* baseData, GameData* _materialData, hand _handle, Faction* _uniformFlag, int _level)
{
    LockedArmour* res = LockedArmour_CONSTRUCTOR_orig(thisptr, baseData, _materialData, _handle, _uniformFlag, _level);
    LockedArmour* overrideRes = CallLockedArmourConstructedCallbacks(thisptr, baseData, _materialData, _handle, _uniformFlag, _level, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_LockedArmour_CONSTRUCTOR,
    "LockedArmour::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&LockedArmour::_CONSTRUCTOR),
    LockedArmour_CONSTRUCTOR_hook, LockedArmour_CONSTRUCTOR_orig)

static Weapon* (*Weapon_CONSTRUCTOR_orig)(Weapon*, GameData*, GameData*, GameData*, hand, int) = NULL;
static Weapon* Weapon_CONSTRUCTOR_hook(Weapon* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle, int _level)
{
    Weapon* res = Weapon_CONSTRUCTOR_orig(thisptr, baseData, companyData, materialData, _handle, _level);
    Weapon* overrideRes = CallWeaponConstructedCallbacks(thisptr, baseData, companyData, materialData, _handle, _level, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Weapon_CONSTRUCTOR,
    "Weapon::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Weapon::_CONSTRUCTOR),
    Weapon_CONSTRUCTOR_hook, Weapon_CONSTRUCTOR_orig)

static Inventory* (*Inventory_CONSTRUCTOR_orig)(Inventory*, RootObject*) = NULL;
static Inventory* Inventory_CONSTRUCTOR_hook(Inventory* thisptr, RootObject* _owner)
{
    Inventory* res = Inventory_CONSTRUCTOR_orig(thisptr, _owner);
    Inventory* overrideRes = CallInventoryConstructedCallbacks(thisptr, _owner, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Inventory_CONSTRUCTOR,
    "Inventory::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Inventory::_CONSTRUCTOR),
    Inventory_CONSTRUCTOR_hook, Inventory_CONSTRUCTOR_orig)

static InventoryItemBase* (*InventoryItemBase_CONSTRUCTOR_orig)(InventoryItemBase*, GameData*, GameData*, GameData*, hand) = NULL;
static InventoryItemBase* InventoryItemBase_CONSTRUCTOR_hook(InventoryItemBase* thisptr, GameData* baseData, GameData* companyData, GameData* materialData, hand _handle)
{
    InventoryItemBase* res = InventoryItemBase_CONSTRUCTOR_orig(thisptr, baseData, companyData, materialData, _handle);
    InventoryItemBase* overrideRes = CallInventoryItemBaseConstructedCallbacks(thisptr, baseData, companyData, materialData, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_InventoryItemBase_CONSTRUCTOR,
    "InventoryItemBase::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&InventoryItemBase::_CONSTRUCTOR),
    InventoryItemBase_CONSTRUCTOR_hook, InventoryItemBase_CONSTRUCTOR_orig)

