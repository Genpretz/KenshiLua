#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/Tasker.h>
#include <kenshi/AI/AI.h>
#include <kenshi/AI/AITaskSystem.h>

static void (*OrdersReceiver_NV_serialise_orig)(OrdersReceiver*, GameData*) = NULL;
static void OrdersReceiver_NV_serialise_hook(OrdersReceiver* thisptr, GameData* data)
{
    OrdersReceiver_NV_serialise_orig(thisptr, data);
    CallOrdersReceiverSerialiseCallbacks(thisptr, data);
}
DEFINE_HOOK_INSTALLER(InstallHook_OrdersReceiver_NV_serialise,
    "OrdersReceiver::_NV_serialise",
    KenshiLib::GetRealAddress(&OrdersReceiver::_NV_serialise),
    OrdersReceiver_NV_serialise_hook, OrdersReceiver_NV_serialise_orig)
