#include "pch.h"
#include "Hooks_Common.h"

// ---------------------------------------------------------------------------
// Hooks for Damages.h
// ---------------------------------------------------------------------------

static Damages* (*Damages_CONSTRUCTOR_orig)(Damages*, float, float, float, float, float) = NULL;
static Damages* Damages_CONSTRUCTOR_hook(Damages* thisptr, float _cut, float _blunt, float _pierce, float bleed, float armour)
{
    Damages* res = Damages_CONSTRUCTOR_orig(thisptr, _cut, _blunt, _pierce, bleed, armour);
    Damages* overrideRes = CallDamagesConstructedCallbacks(thisptr, _cut, _blunt, _pierce, bleed, armour, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_Damages_CONSTRUCTOR,
    "Damages::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(static_cast<Damages* (Damages::*)(float, float, float, float, float)>(&Damages::_CONSTRUCTOR)),
    Damages_CONSTRUCTOR_hook, Damages_CONSTRUCTOR_orig)


