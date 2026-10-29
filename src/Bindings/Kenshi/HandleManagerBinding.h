#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class HandleManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.HandleManager"; }
    static void registerBinding(lua_State* L);

    static int getRedirect(lua_State* L);
    static int removeRedirect(lua_State* L);
    static int clearRedirectForHandle(lua_State* L);
    static int reset(lua_State* L);
    static int setUnloaded(lua_State* L);
    static int destroy(lua_State* L);
    static int getAnything(lua_State* L);
    static int getTownBase(lua_State* L);
    static int getTown(lua_State* L);
    static int getAnythingButBase(lua_State* L);
    static int getShopTrader(lua_State* L);
    static int getBuilding(lua_State* L);
    static int getBuilding_UseableStuff(lua_State* L);
    static int getCharacter(lua_State* L);
    static int getPlatoon(lua_State* L);
    static int getItem(lua_State* L);
    static int isPlayerFaction(lua_State* L);
    static int addExistingObjectHandleToZone(lua_State* L);
    static int getFromDeathParade(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
};

} // namespace KenshiLua

