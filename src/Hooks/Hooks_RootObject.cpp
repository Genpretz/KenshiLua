#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/RootObject.h>
#include <kenshi/RootObjectBase.h>

static RootObjectBase* (*RootObjectBase_CONSTRUCTOR_orig)(RootObjectBase*, GameData*, Faction*, hand) = NULL;
static RootObjectBase* RootObjectBase_CONSTRUCTOR_hook(RootObjectBase* thisptr, GameData* data, Faction* faction, hand handle)
{
    RootObjectBase* res = RootObjectBase_CONSTRUCTOR_orig(thisptr, data, faction, handle);
    RootObjectBase* overrideRes = CallRootObjectBaseConstructedCallbacks(thisptr, data, faction, handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_RootObjectBase_CONSTRUCTOR,
    "RootObjectBase::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&RootObjectBase::_CONSTRUCTOR),
    RootObjectBase_CONSTRUCTOR_hook, RootObjectBase_CONSTRUCTOR_orig)

static RootObject* (*RootObject_CONSTRUCTOR_orig)(RootObject*, GameData*, Faction*, hand) = NULL;
static RootObject* RootObject_CONSTRUCTOR_hook(RootObject* thisptr, GameData* data, Faction* faction, hand handle)
{
    RootObject* res = RootObject_CONSTRUCTOR_orig(thisptr, data, faction, handle);
    RootObject* overrideRes = CallRootObjectConstructedCallbacks(thisptr, data, faction, handle, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_RootObject_CONSTRUCTOR,
    "RootObject::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&RootObject::_CONSTRUCTOR),
    RootObject_CONSTRUCTOR_hook, RootObject_CONSTRUCTOR_orig)
