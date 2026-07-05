#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class hand;
std::size_t hash_value(const hand& h);

namespace KenshiLua
{
class handBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.hand"; }
    static void registerBinding(lua_State* L);
    static int push(lua_State* L, const hand& h);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int toString(lua_State* L);
    static int fromString(lua_State* L);
    static int getCharacter(lua_State* L);
    static int getPlatoon(lua_State* L);
    static int getActivePlatoon(lua_State* L);
    static int getBuilding(lua_State* L);
    static int getItem(lua_State* L);
    static int getRootObject(lua_State* L);
    static int getRootObjectBase(lua_State* L);
    static int getTown(lua_State* L);
    static int debugWhatHappenedToMe(lua_State* L);
    static int setNull(lua_State* L);
    static int isNull(lua_State* L);
    static int isValid(lua_State* L);
    static int canCastToRootObject(lua_State* L);
};
}