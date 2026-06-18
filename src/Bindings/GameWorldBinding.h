#pragma once

extern "C" {
#include <lua.h>
}

class GameWorld;

namespace KenshiLua
{

class GameWorldBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameWorld"; }

    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    static int getCameraCenter(lua_State* L);
    static int isPaused(lua_State* L);
    static int getFrameSpeedMultiplier(lua_State* L);
    static int getCameraPos(lua_State* L);
    static int getLightLevel(lua_State* L);

    static int setPaused(lua_State* L);
    static int setGameSpeed(lua_State* L);
    static int setFrameSpeedMultiplier(lua_State* L);
    static int showMessage(lua_State* L);
    static int playSound(lua_State* L);
    static int getPlayer(lua_State* L);
};

} // namespace KenshiLua