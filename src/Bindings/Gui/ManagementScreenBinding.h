#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ManagementScreenBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ManagementScreen"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int update(lua_State* L);
    static int clear(lua_State* L);
    static int getVisible(lua_State* L);
    static int setVisible(lua_State* L);
    static int getCurrentTab(lua_State* L);
    static int getTab(lua_State* L);
    static int getWidget(lua_State* L);
    static int refresh(lua_State* L);
    static int refreshResearchList(lua_State* L);
    static int refreshResearchRate(lua_State* L);
    static int refreshDiplomacy(lua_State* L);
    static int refreshSquads(lua_State* L);
    static int refreshMap(lua_State* L);
    static int showRoads(lua_State* L);
    static int addSquadToMap(lua_State* L);
    static int removeSquadFromMap(lua_State* L);
    static int resetSquads(lua_State* L);
    static int refreshMessages(lua_State* L);
    static int refreshAI(lua_State* L);
    static int showDebugMarker(lua_State* L);
    static int _CONSTRUCTOR(lua_State* L);
    static int updateResearchListRate(lua_State* L);
    static int refreshResearchListDescription(lua_State* L);
};
}