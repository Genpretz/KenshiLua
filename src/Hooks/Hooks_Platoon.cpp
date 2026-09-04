#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Platoon.h
// ---------------------------------------------------------------------------

static bool (*ActivePlatoon_addActiveObject_orig)(ActivePlatoon*, RootObject*) = NULL;
static bool ActivePlatoon_addActiveObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    bool res = ActivePlatoon_addActiveObject_orig(thisptr, c);
    CallPlatoonMemberAddedCallbacks(thisptr, c);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_AddActiveObject,
    "ActivePlatoon::_NV_addActiveObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_addActiveObject),
    ActivePlatoon_addActiveObject_hook, ActivePlatoon_addActiveObject_orig)

static bool (*ActivePlatoon_removeObject_orig)(ActivePlatoon*, RootObject*) = NULL;
static bool ActivePlatoon_removeObject_hook(ActivePlatoon* thisptr, RootObject* c)
{
    bool res = ActivePlatoon_removeObject_orig(thisptr, c);
    CallPlatoonMemberRemovedCallbacks(thisptr, c);
    return res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_RemoveObject,
    "ActivePlatoon::_NV_removeObject",
    KenshiLib::GetRealAddress(&ActivePlatoon::_NV_removeObject),
    ActivePlatoon_removeObject_hook, ActivePlatoon_removeObject_orig)

static void (*Platoon_taskIsComplete_orig)(Platoon*, Tasker*) = NULL;
static void Platoon_taskIsComplete_hook(Platoon* thisptr, Tasker* t)
{
    Platoon_taskIsComplete_orig(thisptr, t);
    CallPlatoonTaskCompleteCallbacks(thisptr, t);
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_TaskIsComplete,
    "Platoon::taskIsComplete",
    KenshiLib::GetRealAddress(&Platoon::taskIsComplete),
    Platoon_taskIsComplete_hook, Platoon_taskIsComplete_orig)

static bool (*Platoon_iBuyStolenGoods_orig)(Platoon*, Item*) = NULL;
static bool Platoon_iBuyStolenGoods_hook(Platoon* thisptr, Item* what)
{
    bool current = Platoon_iBuyStolenGoods_orig(thisptr, what);
    return CallPlatoonIBuyStolenGoodsCallbacks(thisptr, what, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_iBuyStolenGoods,
    "Platoon::iBuyStolenGoods",
    KenshiLib::GetRealAddress(&Platoon::iBuyStolenGoods),
    Platoon_iBuyStolenGoods_hook, Platoon_iBuyStolenGoods_orig)

static bool (*Platoon_iBuyIllegalGoods_orig)(Platoon*) = NULL;
static bool Platoon_iBuyIllegalGoods_hook(Platoon* thisptr)
{
    bool current = Platoon_iBuyIllegalGoods_orig(thisptr);
    return CallPlatoonIBuyIllegalGoodsCallbacks(thisptr, current);
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_iBuyIllegalGoods,
    "Platoon::iBuyIllegalGoods",
    KenshiLib::GetRealAddress(&Platoon::iBuyIllegalGoods),
    Platoon_iBuyIllegalGoods_hook, Platoon_iBuyIllegalGoods_orig)

static void (*Platoon_NV_loadFromSerialise_orig)(Platoon*, GameSaveState*) = NULL;
static void Platoon_NV_loadFromSerialise_hook(Platoon* thisptr, GameSaveState* state)
{
    Platoon_NV_loadFromSerialise_orig(thisptr, state);
    CallPlatoonLoadFromSerialiseCallbacks(thisptr, state);
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_NV_loadFromSerialise,
    "Platoon::_NV_loadFromSerialise",
    KenshiLib::GetRealAddress(&Platoon::_NV_loadFromSerialise),
    Platoon_NV_loadFromSerialise_hook, Platoon_NV_loadFromSerialise_orig)

static Platoon* (*Platoon_CONSTRUCTOR_orig)(Platoon*, Faction*, GameData*, GameData*, const Ogre::Vector3&, bool) = NULL;
static Platoon* Platoon_CONSTRUCTOR_hook(Platoon* thisptr, Faction* f, GameData* _squadTemplate, GameData* platoonState, const Ogre::Vector3& p, bool _persistent)
{
    Platoon* res = Platoon_CONSTRUCTOR_orig(thisptr, f, _squadTemplate, platoonState, p, _persistent);
    Platoon* overrideRes = CallPlatoonConstructedCallbacks(thisptr, f, _squadTemplate, platoonState, p, _persistent, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Platoon_CONSTRUCTOR,
    "Platoon::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Platoon::_CONSTRUCTOR),
    Platoon_CONSTRUCTOR_hook, Platoon_CONSTRUCTOR_orig)

static ActivePlatoon* (*ActivePlatoon_CONSTRUCTOR_orig)(ActivePlatoon*, Platoon*, DataObjectContainer*, Faction*, GameData*, Tasker*, const Ogre::Vector3&) = NULL;
static ActivePlatoon* ActivePlatoon_CONSTRUCTOR_hook(ActivePlatoon* thisptr, Platoon* my, DataObjectContainer* doc, Faction* f, GameData* d, Tasker* _currentGoal, const Ogre::Vector3& _posOffset)
{
    ActivePlatoon* res = ActivePlatoon_CONSTRUCTOR_orig(thisptr, my, doc, f, d, _currentGoal, _posOffset);
    ActivePlatoon* overrideRes = CallActivePlatoonConstructedCallbacks(thisptr, my, doc, f, d, _currentGoal, _posOffset, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ActivePlatoon_CONSTRUCTOR,
    "ActivePlatoon::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ActivePlatoon::_CONSTRUCTOR),
    ActivePlatoon_CONSTRUCTOR_hook, ActivePlatoon_CONSTRUCTOR_orig)
