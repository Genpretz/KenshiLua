#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class GameDataContainerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.GameDataContainer"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int createNewData(lua_State* L);
    static int getDataByName(lua_State* L);
    static int renameData(lua_State* L);
    static int removeData(lua_State* L);
    static int removeDuplicatesOf(lua_State* L);
    static int removeAllDataOfType(lua_State* L);
    static int clearInstances(lua_State* L);
    static int clearButDontDestroy(lua_State* L);
    static int clearButDontDestroyPlatoons(lua_State* L);
    static int clearAndDestroy(lua_State* L);
    static int getNewID(lua_State* L);
    static int destroyData(lua_State* L);
    static int preLoadAllReferencePtrs(lua_State* L);
    static int clearAllReferencePtrs(lua_State* L);
    static int setName(lua_State* L);
    static int checkForDuplicates(lua_State* L);
    static int addNewData(lua_State* L);
    static int getData(lua_State* L);
    static int getDataOfType(lua_State* L);
    static int _getAllData(lua_State* L);
    static int loadGameDataReturn(lua_State* L);
    static int load(lua_State* L);
    static int save(lua_State* L);
    static int flushKillList(lua_State* L);
    static int destroyHomelessData(lua_State* L);
    static int findAllDataThatReferencesThis(lua_State* L);
    static int _addToKillList(lua_State* L);
};
}