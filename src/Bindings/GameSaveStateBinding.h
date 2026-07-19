#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameSaveStateBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameSaveState"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int generateNewInstanceID(lua_State* L);
    static int generateStateID(lua_State* L);
    static int createState(lua_State* L);
    static int hasState(lua_State* L);
    static int getState(lua_State* L);
    static int numStates(lua_State* L);
    static int getPos(lua_State* L);
    static int getRot(lua_State* L);
    static int getTheInstancesData(lua_State* L);
    static int createFromSerialisedInstanceData(lua_State* L);
    static int addState(lua_State* L);
    static int getInstanceID(lua_State* L);
    // Commented out as this method is not exported by kenshilib:
    // static int getAllStates(lua_State* L);
    static int isValid(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}
