#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class Contract_HiredAllyBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Contract_HiredAlly"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getDesiredTravelSpeed(lua_State* L);
    static int _NV_getDesiredTravelSpeed(lua_State* L);
    static int activateAndSetup(lua_State* L);
    static int _NV_activateAndSetup(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int assessNeutral(lua_State* L);
    static int _NV_assessNeutral(lua_State* L);
    static int assessEnemy(lua_State* L);
    static int _NV_assessEnemy(lua_State* L);
    static int notifyBetrayal(lua_State* L);
    static int _NV_notifyBetrayal(lua_State* L);
    static int endPackage(lua_State* L);
    static int _NV_endPackage(lua_State* L);
    static int showEndedMessage(lua_State* L);
    static int _NV_showEndedMessage(lua_State* L);
    static int signalEnd(lua_State* L);
    static int _NV_signalEnd(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
    static int wantsRenewButton(lua_State* L);
    static int _NV_wantsRenewButton(lua_State* L);
    static int showManagementPanelCallback(lua_State* L);
    static int _NV_showManagementPanelCallback(lua_State* L);
};
}
