#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Item.h
// ---------------------------------------------------------------------------

static void (*Item_notifyTheftFrom_orig)(Item*, RootObject*) = NULL;
static void Item_notifyTheftFrom_hook(Item* thisptr, RootObject* obj)
{
    Item_notifyTheftFrom_orig(thisptr, obj);
    CallItemStolenCallbacks(thisptr, obj);
}
DEFINE_HOOK_INSTALLER(InstallHook_Item_NotifyTheftFrom,
    "Item::_NV_notifyTheftFrom",
    KenshiLib::GetRealAddress(static_cast<void (Item::*)(RootObject*)>(&Item::_NV_notifyTheftFrom)),
    Item_notifyTheftFrom_hook, Item_notifyTheftFrom_orig)

static Item* (*Item_CONSTRUCTOR_orig)(Item*, GameData*, GameData*, GameData*, hand) = NULL;
static Item* Item_CONSTRUCTOR_hook(Item* thisptr, GameData* baseData, GameData* companyData, GameData* _materialData, hand _handle)
{
    Item* res = Item_CONSTRUCTOR_orig(thisptr, baseData, companyData, _materialData, _handle);
    Item* overrideRes = CallItemConstructedCallbacks(thisptr, baseData, companyData, _materialData, _handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Item_CONSTRUCTOR,
    "Item::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Item::_CONSTRUCTOR),
    Item_CONSTRUCTOR_hook, Item_CONSTRUCTOR_orig)
