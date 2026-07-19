#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class RootObjectFactoryBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.RootObjectFactory"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int mainThreadUpdate(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);

    static int create(lua_State* L);
    static int createBuilding(lua_State* L);
    static int createLocationNode(lua_State* L);
    static int createItem(lua_State* L);
    static int copyItem(lua_State* L);
    static int chooseDataFromList(lua_State* L);
    static int chooseDataFromListWithVals(lua_State* L);
    static int getValsFromDataInList(lua_State* L);
    static int createCharacterForBuilding(lua_State* L);
    static int createRandomCharacter(lua_State* L);
    static int createRandomUnloadedCharacter(lua_State* L);
    static int createRandomSquad(lua_State* L);
    static int createRandomUnloadedSquad(lua_State* L);
    static int populateBuilding(lua_State* L);
    static int process(lua_State* L);
};
}
