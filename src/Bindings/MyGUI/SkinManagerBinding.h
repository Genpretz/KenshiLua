#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class SkinManagerBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.SkinManager"; }
    static void registerBinding(lua_State* L);

    static MyGUI::SkinManager* getSkinManager(lua_State* L, int idx);

    static int getInstance(lua_State* L);
    static int isExist(lua_State* L);
    static int getDefaultSkin(lua_State* L);
    static int setDefaultSkin(lua_State* L);
};

} // namespace KenshiLua
