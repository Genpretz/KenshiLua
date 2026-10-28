#pragma once
#include "kenshi/Research.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ResearchBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.Research"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _reset(lua_State* L);
    static int _setup(lua_State* L);
    static int getArmourCraftLevel(lua_State* L);
    static int startResearch(lua_State* L);
    static int stopResearch(lua_State* L);
    static int completeResearch(lua_State* L);
    static int isFinished(lua_State* L);
    static int isBuildingResearched(lua_State* L);
    static int getETA(lua_State* L);
    static int payCosts(lua_State* L);
    static int canPayCosts(lua_State* L);
    static int getBlueprintsFor(lua_State* L);
    static int staticUpdate(lua_State* L);
    static int getCurrentResearchRate(lua_State* L);
    static int serialise(lua_State* L);
    static int load(lua_State* L);
    static int progressResearch(lua_State* L);
    static int checkRequirementsForInvisibility(lua_State* L);
    static int checkRequirements(lua_State* L);
    static int checkRequirements_andQueue(lua_State* L);
    static int isInQueue(lua_State* L);
    static int _updateTheAllList(lua_State* L);
    static int setResearchDeskLevel(lua_State* L);
    static int refreshTheoreticalTechLevel(lua_State* L);
    static int needsATechBench(lua_State* L);
    static int hasPaidFor(lua_State* L);
    static int getResearchDeskLevel(lua_State* L);
    static int hasArtifact(lua_State* L);
    static int getResearchItem(lua_State* L);
    static int getResearchProgress(lua_State* L);
    static int getCategories(lua_State* L);
};
}
