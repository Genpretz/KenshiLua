#pragma once
#include "kenshi/Item.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BlueprintItemBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BlueprintItem"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int getClassType(lua_State* L);
    static int _NV_getClassType(lua_State* L);
    static int getItemWeight(lua_State* L);
    static int _NV_getItemWeight(lua_State* L);
    static int getValueSingle(lua_State* L);
    static int _NV_getValueSingle(lua_State* L);
    static int getResearchData(lua_State* L);
    static int learnResearch(lua_State* L);
    static int getGUIData(lua_State* L);
    static int _NV_getGUIData(lua_State* L);
};
}
