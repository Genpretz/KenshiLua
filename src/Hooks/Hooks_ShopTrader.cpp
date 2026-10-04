#include "pch.h"
#include "Hooks_Common.h"

#include <kenshi/ShopTrader.h>

static ShopTrader* (*ShopTrader_CONSTRUCTOR_orig)(ShopTrader*, Character*) = NULL;
static ShopTrader* ShopTrader_CONSTRUCTOR_hook(ShopTrader* thisptr, Character* character)
{
    ShopTrader* res = ShopTrader_CONSTRUCTOR_orig(thisptr, character);
    ShopTrader* overrideRes = CallShopTraderConstructedCallbacks(thisptr, character, res);
    return overrideRes ? overrideRes : res;
}
DEFINE_HOOK_INSTALLER(InstallHook_ShopTrader_CONSTRUCTOR,
    "ShopTrader::_CONSTRUCTOR",
    KenshiLib::GetRealAddress(&ShopTrader::_CONSTRUCTOR),
    ShopTrader_CONSTRUCTOR_hook, ShopTrader_CONSTRUCTOR_orig)
