#pragma once

#include "pch.h"
#include <MyGUI.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{

class IntPointBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.IntPoint"; }
    static void registerBinding(lua_State* L);
};

class IntSizeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.IntSize"; }
    static void registerBinding(lua_State* L);
};

class IntCoordBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.IntCoord"; }
    static void registerBinding(lua_State* L);
};

class IntRectBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.IntRect"; }
    static void registerBinding(lua_State* L);
};

class FloatPointBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.FloatPoint"; }
    static void registerBinding(lua_State* L);
};

class FloatSizeBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.FloatSize"; }
    static void registerBinding(lua_State* L);
};

class FloatCoordBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.FloatCoord"; }
    static void registerBinding(lua_State* L);
};

class FloatRectBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.FloatRect"; }
    static void registerBinding(lua_State* L);
};

class ColourBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.MyGUI.Colour"; }
    static void registerBinding(lua_State* L);
};

} // namespace KenshiLua
