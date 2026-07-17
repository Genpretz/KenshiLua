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

    static int getSourceContainer(lua_State* L);
    static int storeHandleList(lua_State* L);
    static int getHandleList(lua_State* L);
    static int storeHandle(lua_State* L);
    static int getHandle(lua_State* L);
    static int updateFrom(lua_State* L);
    static int add(lua_State* L);
    static int getGameDataReferenceObject(lua_State* L);
    static int removeFromList(lua_State* L);
    static int getFromList(lua_State* L);
    static int getFromList_random(lua_State* L);
    static int getAllFromList(lua_State* L);
    static int getReferenceList(lua_State* L);
    static int getReferenceListIfExists(lua_State* L);
    static int _getReferenceList_nonConst(lua_State* L);
    static int getAllFromListAsDatas(lua_State* L);
    static int getFromListAsData(lua_State* L);
    static int getValueFromList(lua_State* L);
    static int addSavedInstancedObject(lua_State* L);
    static int getInstances(lua_State* L);
    static int getColor(lua_State* L);
    static int setColor(lua_State* L);
    static int addANewInstancedObject(lua_State* L);
};
}