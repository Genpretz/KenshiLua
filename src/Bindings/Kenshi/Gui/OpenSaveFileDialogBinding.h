#pragma once

#include "kenshi/gui/OpenSaveFileDialog.h"

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

    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int setDialogInfo(lua_State* L);
    static int setCurrentFolder(lua_State* L);
    static int getCurrentFolder(lua_State* L);
    static int setFileName(lua_State* L);
    static int getFileName(lua_State* L);
    static int setFileMask(lua_State* L);
    static int getFileMask(lua_State* L);
    static int update(lua_State* L);
    static int accept(lua_State* L);
    static int cancel(lua_State* L);
    static int upFolder(lua_State* L);
    static int notifyDirectoryComboAccept(lua_State* L);
    static int notifyDirectoryComboChangePosition(lua_State* L);
    static int notifyListChangePosition(lua_State* L);
    static int notifyListSelectAccept(lua_State* L);
    static int closeWindow(lua_State* L);
};
}