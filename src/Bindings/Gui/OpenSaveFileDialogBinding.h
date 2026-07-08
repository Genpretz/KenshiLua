#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class OpenSaveFileDialogBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.OpenSaveFileDialog"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int setDialogInfo(lua_State* L);
    static int setCurrentFolder(lua_State* L);
    static int setFileName(lua_State* L);
    static int setFileMask(lua_State* L);
    static int update(lua_State* L);
};
}