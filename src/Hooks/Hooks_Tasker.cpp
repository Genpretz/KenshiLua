#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/Tasker.h>

static Tasker* (*Tasker_CONSTRUCTOR_orig)(Tasker*) = NULL;
static Tasker* Tasker_CONSTRUCTOR_hook(Tasker* thisptr)
{
    Tasker* res = Tasker_CONSTRUCTOR_orig(thisptr);
    Tasker* overrideRes = CallTaskerConstructedCallbacks(thisptr, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Tasker_CONSTRUCTOR,
    "Tasker::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&Tasker::_CONSTRUCTOR),
    Tasker_CONSTRUCTOR_hook, Tasker_CONSTRUCTOR_orig)
