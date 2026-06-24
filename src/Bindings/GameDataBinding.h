#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameData"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int isValid(lua_State* L);
    static int destroy(lua_State* L);
    static int initialise(lua_State* L);
    static int loadFromFile(lua_State* L);
    static int saveToFile(lua_State* L);
    static int isValueActive(lua_State* L);
    static int isRefActive(lua_State* L);
    static int addFileName(lua_State* L);
    static int addString(lua_State* L);
    static int addToList(lua_State* L);
    static int findInList(lua_State* L);
    static int clearList(lua_State* L);
    static int clearEverything(lua_State* L);
    static int clearInstances(lua_State* L);
    static int getListSize(lua_State* L);
    static int listExists(lua_State* L);
    static int listExistsAndNotEmpty(lua_State* L);
    static int deleteInstancedObject(lua_State* L);
    static int getNewID(lua_State* L);
    static int getColorVec(lua_State* L);
    static int addDeletedInstance(lua_State* L);
};
}