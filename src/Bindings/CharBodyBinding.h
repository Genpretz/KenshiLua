#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class CharBodyBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.CharBody"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int notifyBodyTaskComplete(lua_State* L);
    static int notifyTaskComplete(lua_State* L);
    static int _NV_notifyTaskComplete(lua_State* L);
    static int notifyTaskImpossible(lua_State* L);
    static int _NV_notifyTaskImpossible(lua_State* L);
    static int isCrouched(lua_State* L);
    static int getPosition(lua_State* L);
    static int _NV_getPosition(lua_State* L);
    static int getName(lua_State* L);
    static int isCharacter(lua_State* L);
    static int _NV_isCharacter(lua_State* L);
    static int getCharacter(lua_State* L);
    static int _NV_getCharacter(lua_State* L);
    static int getUpFromRagdoll(lua_State* L);
    static int getPlatoon(lua_State* L);
    static int _NV_getPlatoon(lua_State* L);
    static int endAction(lua_State* L);
    static int isIdle(lua_State* L);
    static int getFaction(lua_State* L);
    static int _endAction(lua_State* L);
    static int _NV__endAction(lua_State* L);
};
}