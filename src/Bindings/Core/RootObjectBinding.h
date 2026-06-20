#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

class RootObject;

namespace KenshiLua
{

class RootObjectBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObject"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int index(lua_State* L);
    static int newindex(lua_State* L);

    // Reads
    static int getName(lua_State* L);
    static int getPosition(lua_State* L);
    static int getRotation(lua_State* L);
    static int getVisible(lua_State* L);
    static int getModelName(lua_State* L);
    static int getMoney(lua_State* L);
    static int getTown(lua_State* L);
    static int getInventory(lua_State* L);

    // Writes
    static int setVisible(lua_State* L);
    static int takeMoney(lua_State* L);
    static int say(lua_State* L);

    // Polymorphic helper
    static int pushRootObject(lua_State* L, RootObject* obj);
};

} // namespace KenshiLua
