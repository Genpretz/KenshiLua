#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class SaveFileSystemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.SaveFileSystem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
    static int log(lua_State* L);
    static int setTemporaryPath(lua_State* L);
    static int fileExists(lua_State* L);
    static int readFile(lua_State* L);
    static int writeFile(lua_State* L);
    static int deleteFile(lua_State* L);
    static int newGame(lua_State* L);
    static int loadGame(lua_State* L);
    static int saveGame(lua_State* L);
    static int sync(lua_State* L);
    static int analyse(lua_State* L);
    static int cleanup(lua_State* L);
    static int scanForResidualTempFolders(lua_State* L);
    static int isTempFolder(lua_State* L);
    static int busy(lua_State* L);
    static int createCurrent(lua_State* L);
    static int threadProc(lua_State* L);
    static int _NV_threadProc(lua_State* L);
    static int addMessage(lua_State* L);
};
}
