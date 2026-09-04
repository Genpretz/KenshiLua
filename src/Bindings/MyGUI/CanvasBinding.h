#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class CanvasBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Canvas"; }
    static void registerBinding(lua_State* L);

    static MyGUI::Canvas* getCanvas(lua_State* L, int idx);

    static int createTexture(lua_State* L);
    static int destroyTexture(lua_State* L);
    static int updateTexture(lua_State* L);
    static int isTextureCreated(lua_State* L);
    static int isTextureManaged(lua_State* L);
    static int setTextureManaged(lua_State* L);
    static int getTextureRealWidth(lua_State* L);
    static int getTextureRealHeight(lua_State* L);
    static int getTextureRealSize(lua_State* L);
    static int getTextureSrcWidth(lua_State* L);
    static int getTextureSrcHeight(lua_State* L);
    static int getTextureSrcSize(lua_State* L);
    static int isTextureSrcSize(lua_State* L);
    static int getTextureName(lua_State* L);
    static int getTextureFormat(lua_State* L);
    static int setResizeMode(lua_State* L);
    static int getResizeMode(lua_State* L);
};

} // namespace KenshiLua
