#pragma once
#include "kenshi/ZoneSmell.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneSmellBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneSmell"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _getSmell(lua_State* L);
    static int isEmpty(lua_State* L);
    static int getSmell(lua_State* L);
    static int getGeneralSmellLevel(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int addSmell(lua_State* L);
};
}
