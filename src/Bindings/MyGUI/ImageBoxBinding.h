#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class ImageBoxBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.ImageBox"; }
    static void registerBinding(lua_State* L);

    static MyGUI::ImageBox* getImageBox(lua_State* L, int idx);

    static int setImageTexture(lua_State* L);
    static int setImageCoord(lua_State* L);
    static int setImageTile(lua_State* L);
    static int setImageIndex(lua_State* L);
    static int getImageIndex(lua_State* L);
    static int getItemCount(lua_State* L);
    static int setItemSelect(lua_State* L);
    static int getItemSelect(lua_State* L);
    static int resetItemSelect(lua_State* L);
    static int setItemResource(lua_State* L);
};

} // namespace KenshiLua
