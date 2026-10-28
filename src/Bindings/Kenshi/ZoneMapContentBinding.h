#pragma once
#include "kenshi/ZoneMapContent.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class ZoneMapContentBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneMapContent"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int isLoadedT(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int threadedUpdate(lua_State* L);
    static int addToUpdateList(lua_State* L);
    static int _reloadAllFoliage(lua_State* L);
    static int getOverlayPixelCoord(lua_State* L);
    static int clearOverlay(lua_State* L);
    static int generateDirtMap(lua_State* L);
    static int addLoadedBuilding(lua_State* L);
    static int loadItems(lua_State* L);
    static int saveItems(lua_State* L);
    static int saveLevelData(lua_State* L);
    static int saveToDisk(lua_State* L);
    static int activate(lua_State* L);
    static int deactivate(lua_State* L);
    static int reFactionBuildingsFromTown(lua_State* L);
    static int updateItemsVisibility(lua_State* L);
    static int _setEnabledStaticGeometry(lua_State* L);
    static int findBuildingTypePublic(lua_State* L);
    static int findBuildingByDataPosition(lua_State* L);
    static int _populateTownsOnNewGame(lua_State* L);
    static int forceLoadAllTheBuildingInteriorVisuals(lua_State* L);
    static int addItem(lua_State* L);
    static int removeItem(lua_State* L);
    static int changeItemZone(lua_State* L);
    static int removeObject(lua_State* L);
    static int _NV_removeObject(lua_State* L);
    static int getFoliageSystem(lua_State* L);
    static int _activate(lua_State* L);
    static int createLoadedItems(lua_State* L);
    static int setLoadedT(lua_State* L);
};
}
