#include "pch.h"
#include "Bindings/GameWorldBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>

#include <ogre/OgreVector3.h>
#include "Bindings/PlayerInterfaceBinding.h"
#include <kenshi/PlayerInterface.h>

namespace KenshiLua
{

static GameWorld* getG(lua_State* L, int idx)
{
    // Allow `GameWorld.method(...)` (no self) by falling back to the global
    // `ou` pointer when there's no userdata on the stack at idx.
    if (lua_isnoneornil(L, idx)) return ::ou;
    return checkObject<GameWorld>(L, idx, GameWorldBinding::getMetatableName());
}

int GameWorldBinding::gc(lua_State* L)       { return noopGc(L); }

int GameWorldBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    // 1. Check the metatable first so obj:method() syntax continues to work.
    luaL_getmetatable(L, GameWorldBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;   // found a method - return it
    lua_pop(L, 2);  // pop nil result + metatable

    // 2. Fall through to raw member variable access.
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "isPaused") == 0) { lua_pushboolean(L, g->isPaused() ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "frameSpeedMultiplier") == 0) { lua_pushnumber(L, g->getFrameSpeedMultiplier()); return 1; }

    // --- special/object members ---
    if (strcmp(key, "cameraCenter") == 0) { pushVector3(L, g->getCameraCenter()); return 1; }
    if (strcmp(key, "cameraPos") == 0) { pushVector3(L, g->getCameraPos()); return 1; }
    if (strcmp(key, "player") == 0) {
        if (!g->player) { lua_pushnil(L); return 1; }
        pushObject<PlayerInterface>(L, g->player, PlayerInterfaceBinding::getMetatableName());
        return 1;
    }

    lua_pushnil(L);
    return 1;
}

int GameWorldBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");

    // --- writable properties ---
    if (strcmp(key, "isPaused") == 0) {
        g->userPause(lua_toboolean(L, 3) != 0);
        return 0;
    }
    if (strcmp(key, "frameSpeedMultiplier") == 0) {
        g->setFrameSpeedMultiplier((float)luaL_checknumber(L, 3));
        return 0;
    }

    return luaL_error(L, "GameWorld: field '%s' is read-only or does not exist", key);
}
int GameWorldBinding::tostring(lua_State* L) { lua_pushstring(L, "GameWorld"); return 1; }

int GameWorldBinding::getCameraCenter(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = g->getCameraCenter();
    pushVector3(L, p);
    return 1;
}

int GameWorldBinding::getCameraPos(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 p = g->getCameraPos();
    pushVector3(L, p);
    return 1;
}

int GameWorldBinding::isPaused(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    lua_pushboolean(L, g && g->isPaused() ? 1 : 0);
    return 1;
}

int GameWorldBinding::getFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (g) lua_pushnumber(L, g->getFrameSpeedMultiplier()); else lua_pushnil(L);
    return 1;
}

int GameWorldBinding::getLightLevel(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) { lua_pushnil(L); return 1; }
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "getLightLevel: expected {x,y,z}");
    int floor  = (int)luaL_optinteger(L, 3, 0);
    bool inside = lua_isnoneornil(L, 4) ? true : (lua_toboolean(L, 4) != 0);
    lua_pushnumber(L, g->getLightLevel(pos, floor, inside));
    return 1;
}

int GameWorldBinding::setPaused(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    g->userPause(lua_toboolean(L, 2) != 0);
    return 0;
}

int GameWorldBinding::setGameSpeed(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    float speed = (float)luaL_checknumber(L, 2);
    bool click = lua_toboolean(L, 3) != 0;
    g->setGameSpeed(speed, click);
    return 0;
}

int GameWorldBinding::setFrameSpeedMultiplier(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    g->setFrameSpeedMultiplier((float)luaL_checknumber(L, 2));
    return 0;
}

int GameWorldBinding::showMessage(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    const char* msg = luaL_checkstring(L, 2);
    bool queued = lua_isnoneornil(L, 3) ? true : (lua_toboolean(L, 3) != 0);
    g->showPlayerAMessage(msg, queued);
    return 0;
}

int GameWorldBinding::playSound(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g) return luaL_error(L, "GameWorld is nil");
    g->playNotification(luaL_checkstring(L, 2));
    return 0;
}

int GameWorldBinding::getPlayer(lua_State* L)
{
    GameWorld* g = getG(L, 1);
    if (!g || !g->player) { lua_pushnil(L); return 1; }
    pushObject<PlayerInterface>(L, g->player, PlayerInterfaceBinding::getMetatableName());
    return 1;
}

void GameWorldBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameWorldBinding::gc },
        { "__tostring", GameWorldBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getCameraCenter",          GameWorldBinding::getCameraCenter },
        { "getCameraPos",             GameWorldBinding::getCameraPos },
        { "isPaused",                 GameWorldBinding::isPaused },
        { "getFrameSpeedMultiplier",  GameWorldBinding::getFrameSpeedMultiplier },
        { "getLightLevel",            GameWorldBinding::getLightLevel },
        { "setPaused",                GameWorldBinding::setPaused },
        { "setGameSpeed",             GameWorldBinding::setGameSpeed },
        { "setFrameSpeedMultiplier",  GameWorldBinding::setFrameSpeedMultiplier },
        { "showMessage",              GameWorldBinding::showMessage },
        { "playSound",                GameWorldBinding::playSound },
        { "getPlayer",                GameWorldBinding::getPlayer },
        { 0, 0 }
    };
    registerClass(L, GameWorldBinding::getMetatableName(), meta, methods, GameWorldBinding::index, GameWorldBinding::newindex);
}

} // namespace KenshiLua
