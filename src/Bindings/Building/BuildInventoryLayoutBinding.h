#pragma once

#include "kenshi/Building/ProductionBuilding.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class BuildInventoryLayoutBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.BuildInventoryLayout"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _CONSTRUCTOR(lua_State* L);
    static int setupSections(lua_State* L);
    static int _NV_setupSections(lua_State* L);
    static int setInput(lua_State* L);
    static int setOutput(lua_State* L);
    static int setInputProgress(lua_State* L);
    static int setInputEnabled(lua_State* L);
    static int setOutputProgress(lua_State* L);
    static int setInputItem(lua_State* L);
    static int setOutputItem(lua_State* L);
    static int _DESTRUCTOR(lua_State* L);
};
}