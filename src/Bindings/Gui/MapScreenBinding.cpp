#include "pch.h"
#include "kenshi\gui\MapScreen.h"
#include "MapScreenBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/ManagementScreenBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/Gui/ToolTipBinding.h"

namespace KenshiLua
{

static MapScreen* getInstance(lua_State* L, int idx)
{
    return checkObject<MapScreen>(L, idx, MapScreenBinding::getMetatableName());
}

// --- Getters for MapScreen ---
static int MapScreen_get_updateTimer(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushnumber(L, instance->updateTimer);
    return 1;
}

static int MapScreen_get_toolTip(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    return pushObject<ToolTip>(L, instance->toolTip, ToolTipBinding::getMetatableName());
}

static int MapScreen_get_mainWidget(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mainWidget);
    return 1;
}

static int MapScreen_get_mapScrollView(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mapScrollView);
    return 1;
}

static int MapScreen_get_mapImage(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mapImage);
    return 1;
}

static int MapScreen_get_cameraMarker(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->cameraMarker);
    return 1;
}

static int MapScreen_get_cameraMarkerSkin(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->cameraMarkerSkin);
    return 1;
}

static int MapScreen_get_zoomUpdated(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushboolean(L, instance->zoomUpdated ? 1 : 0);
    return 1;
}

static int MapScreen_get_zoomValueBase(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushnumber(L, instance->zoomValueBase);
    return 1;
}

static int MapScreen_get_zoomValueMax(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushnumber(L, instance->zoomValueMax);
    return 1;
}

static int MapScreen_get_zoomValueCurrent(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushnumber(L, instance->zoomValueCurrent);
    return 1;
}

static int MapScreen_get_zoomLevelCurrent(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushinteger(L, (lua_Integer)instance->zoomLevelCurrent);
    return 1;
}

static int MapScreen_get_mapOverlaysContainer(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mapOverlaysContainer);
    return 1;
}

static int MapScreen_get_zoomLevels(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_createtable(L, 3, 0);
    for (int i = 0; i < 3; i++) {
        lua_pushnumber(L, instance->zoomLevels[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int MapScreen_get_mapMarkerMovement(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushlightuserdata(L, (void*)instance->mapMarkerMovement);
    return 1;
}

static int MapScreen_get_mapMarkerMovementPosition(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    pushVector3(L, instance->mapMarkerMovementPosition);
    return 1;
}

static int MapScreen_get_mapMarkerMovementFadeOutDelay(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushnumber(L, instance->mapMarkerMovementFadeOutDelay);
    return 1;
}

static int MapScreen_get_mapDragging(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    lua_pushboolean(L, instance->mapDragging ? 1 : 0);
    return 1;
}

static int MapScreen_get_mapMouseLastPosition(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    pushVector2(L, instance->mapMouseLastPosition);
    return 1;
}

static int MapScreen_get_mapOffsetView(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    pushVector2(L, instance->mapOffsetView);
    return 1;
}

static int MapScreen_get_worldSize(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    pushVector2(L, instance->worldSize);
    return 1;
}

// --- Setters for MapScreen ---
static int MapScreen_set_updateTimer(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->updateTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MapScreen_set_toolTip(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->toolTip = lua_isnoneornil(L, 2) ? nullptr : checkObject<ToolTip>(L, 2, ToolTipBinding::getMetatableName());
    return 0;
}

static int MapScreen_set_zoomUpdated(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->zoomUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MapScreen_set_zoomValueBase(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->zoomValueBase = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MapScreen_set_zoomValueMax(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->zoomValueMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MapScreen_set_zoomValueCurrent(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->zoomValueCurrent = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MapScreen_set_zoomLevelCurrent(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->zoomLevelCurrent = (MapZoomLevel)luaL_checkinteger(L, 2);
    return 0;
}

static int MapScreen_set_zoomLevels(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    if (lua_istable(L, 2)) {
        for (int i = 0; i < 3; i++) {
            lua_rawgeti(L, 2, i + 1);
            instance->zoomLevels[i] = (float)lua_tonumber(L, -1);
            lua_pop(L, 1);
        }
    }
    return 0;
}

static int MapScreen_set_mapMarkerMovementPosition(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    readVector3(L, 2, instance->mapMarkerMovementPosition);
    return 0;
}

static int MapScreen_set_mapMarkerMovementFadeOutDelay(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->mapMarkerMovementFadeOutDelay = (float)luaL_checknumber(L, 2);
    return 0;
}

static int MapScreen_set_mapDragging(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    instance->mapDragging = lua_toboolean(L, 2) != 0;
    return 0;
}

static int MapScreen_set_mapMouseLastPosition(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    readVector2(L, 2, instance->mapMouseLastPosition);
    return 0;
}

static int MapScreen_set_mapOffsetView(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    readVector2(L, 2, instance->mapOffsetView);
    return 0;
}

static int MapScreen_set_worldSize(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");
    readVector2(L, 2, instance->worldSize);
    return 0;
}

int MapScreenBinding::_CONSTRUCTOR(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    ManagementScreen* screen = checkObject<ManagementScreen>(L, 2, ManagementScreenBinding::getMetatableName());
    MapScreen* result = instance->_CONSTRUCTOR(screen);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int MapScreenBinding::_DESTRUCTOR(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int MapScreenBinding::clear(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->clear();
    return 0;
}

int MapScreenBinding::getVisible(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MapScreenBinding::centerCamera(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->centerCamera();
    return 0;
}

int MapScreenBinding::clearTempMarkers(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->clearTempMarkers();
    return 0;
}

int MapScreenBinding::refresh(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->refresh();
    return 0;
}

int MapScreenBinding::update(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->update();
    return 0;
}

int MapScreenBinding::addSquad(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    Platoon* squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->addSquad(squad);
    return 0;
}

int MapScreenBinding::removeSquad(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    Platoon* squad = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    instance->removeSquad(squad);
    return 0;
}

int MapScreenBinding::hide(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->hide();
    return 0;
}

int MapScreenBinding::setMovementMarker(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    float time = (float)luaL_checknumber(L, 3);
    instance->setMovementMarker(p, time);
    return 0;
}

int MapScreenBinding::showRoads(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showRoads(on);
    return 0;
}

int MapScreenBinding::updateZoom(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->updateZoom();
    return 0;
}

int MapScreenBinding::updateCameraMarker(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->updateCameraMarker();
    return 0;
}

int MapScreenBinding::refreshTowns(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->refreshTowns();
    return 0;
}

int MapScreenBinding::refreshSquads(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->refreshSquads();
    return 0;
}

int MapScreenBinding::updateCharacterMarker(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    RootObjectBase* object = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    instance->updateCharacterMarker(object);
    return 0;
}

int MapScreenBinding::getMouseWorldPosition(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    Ogre::Vector3 position;
    readVector3(L, 2, position);
    bool result = instance->getMouseWorldPosition(position);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int MapScreenBinding::setupRoads(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->setupRoads();
    return 0;
}

int MapScreenBinding::updateRoads(lua_State* L)
{
    MapScreen* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "MapScreen is nil");

    instance->updateRoads();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 69: void updatePlayerTownMapMarker(...) - non-string reference arg
  line 76: MyGUI::types::TPoint<int> worldToMapCoords(...) - unsupported return type
  line 77: Ogre::Vector3 mapCoordsToWorld(...) - unsupported arg type
  line 78: void mapMouseWheel(...) - unsupported arg type
  line 79: void mapMousePressed(...) - unsupported arg type
  line 80: void mapMouseReleased(...) - unsupported arg type
  line 83: void centerButton(...) - unsupported arg type
  line 84: void zoomInButton(...) - unsupported arg type
  line 85: void zoomOutButton(...) - unsupported arg type
  line 86: const MyGUI::Colour& getMarkerColor(...) - static method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - MapScreen_get_mainWidget: MyGUI::Widget* (unbound pointer)
  - MapScreen_get_mapScrollView: MyGUI::ScrollView* (unbound pointer)
  - MapScreen_get_mapImage: MyGUI::ImageBox* (unbound pointer)
  - MapScreen_get_cameraMarker: MyGUI::ImageBox* (unbound pointer)
  - MapScreen_get_cameraMarkerSkin: MyGUI::RotatingSkin* (unbound pointer)
  - MapScreen_get_mapOverlaysContainer: MyGUI::Widget* (unbound pointer)
  - MapScreen_get_mapMarkerMovement: MyGUI::ImageBox* (unbound pointer)
  - MapScreenBinding::_CONSTRUCTOR: MapScreen* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 98: zoomCenterOffset (Ogre::Vector4) - unsupported type
  line 102: mapMarkersTowns (ogre_unordered_map<hand, MapScreen::MapMarkerTown*>::type) - unsupported type
  line 103: mapMarkersTownsNew (Ogre::FastArray<hand>) - unsupported type
  line 104: mapMarkersCharacters (ogre_unordered_map<hand, MapScreen::MapMarkerCharacter*>::type) - unsupported type
  line 108: squadsList (ogre_unordered_set<hand>::type) - unsupported type
  line 112: worldBounds (Ogre::Vector4) - unsupported type
  line 125: roads (lektor<MapScreen::MapRoad*>) - unsupported type
*/

int MapScreenBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int MapScreenBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.MapScreen object");
    return 1;
}

void MapScreenBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       MapScreenBinding::gc },
        { "__tostring", MapScreenBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", MapScreenBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", MapScreenBinding::_DESTRUCTOR },
        { "clear", MapScreenBinding::clear },
        { "getVisible", MapScreenBinding::getVisible },
        { "centerCamera", MapScreenBinding::centerCamera },
        { "clearTempMarkers", MapScreenBinding::clearTempMarkers },
        { "refresh", MapScreenBinding::refresh },
        { "update", MapScreenBinding::update },
        { "addSquad", MapScreenBinding::addSquad },
        { "removeSquad", MapScreenBinding::removeSquad },
        { "hide", MapScreenBinding::hide },
        { "setMovementMarker", MapScreenBinding::setMovementMarker },
        { "showRoads", MapScreenBinding::showRoads },
        { "updateZoom", MapScreenBinding::updateZoom },
        { "updateCameraMarker", MapScreenBinding::updateCameraMarker },
        { "refreshTowns", MapScreenBinding::refreshTowns },
        { "refreshSquads", MapScreenBinding::refreshSquads },
        { "updateCharacterMarker", MapScreenBinding::updateCharacterMarker },
        { "getMouseWorldPosition", MapScreenBinding::getMouseWorldPosition },
        { "setupRoads", MapScreenBinding::setupRoads },
        { "updateRoads", MapScreenBinding::updateRoads },
        { 0, 0 }
    };

    registerClass(
        L, 
        MapScreenBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, MapScreenBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "updateTimer", MapScreen_get_updateTimer);
    registerGetter(L, "toolTip", MapScreen_get_toolTip);
    registerGetter(L, "mainWidget", MapScreen_get_mainWidget);
    registerGetter(L, "mapScrollView", MapScreen_get_mapScrollView);
    registerGetter(L, "mapImage", MapScreen_get_mapImage);
    registerGetter(L, "cameraMarker", MapScreen_get_cameraMarker);
    registerGetter(L, "cameraMarkerSkin", MapScreen_get_cameraMarkerSkin);
    registerGetter(L, "zoomUpdated", MapScreen_get_zoomUpdated);
    registerGetter(L, "zoomValueBase", MapScreen_get_zoomValueBase);
    registerGetter(L, "zoomValueMax", MapScreen_get_zoomValueMax);
    registerGetter(L, "zoomValueCurrent", MapScreen_get_zoomValueCurrent);
    registerGetter(L, "zoomLevelCurrent", MapScreen_get_zoomLevelCurrent);
    registerGetter(L, "mapOverlaysContainer", MapScreen_get_mapOverlaysContainer);
    registerGetter(L, "zoomLevels", MapScreen_get_zoomLevels);
    registerGetter(L, "mapMarkerMovement", MapScreen_get_mapMarkerMovement);
    registerGetter(L, "mapMarkerMovementPosition", MapScreen_get_mapMarkerMovementPosition);
    registerGetter(L, "mapMarkerMovementFadeOutDelay", MapScreen_get_mapMarkerMovementFadeOutDelay);
    registerGetter(L, "mapDragging", MapScreen_get_mapDragging);
    registerGetter(L, "mapMouseLastPosition", MapScreen_get_mapMouseLastPosition);
    registerGetter(L, "mapOffsetView", MapScreen_get_mapOffsetView);
    registerGetter(L, "worldSize", MapScreen_get_worldSize);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "updateTimer", MapScreen_set_updateTimer);
    registerSetter(L, "toolTip", MapScreen_set_toolTip);
    registerSetter(L, "zoomUpdated", MapScreen_set_zoomUpdated);
    registerSetter(L, "zoomValueBase", MapScreen_set_zoomValueBase);
    registerSetter(L, "zoomValueMax", MapScreen_set_zoomValueMax);
    registerSetter(L, "zoomValueCurrent", MapScreen_set_zoomValueCurrent);
    registerSetter(L, "zoomLevelCurrent", MapScreen_set_zoomLevelCurrent);
    registerSetter(L, "zoomLevels", MapScreen_set_zoomLevels);
    registerSetter(L, "mapMarkerMovementPosition", MapScreen_set_mapMarkerMovementPosition);
    registerSetter(L, "mapMarkerMovementFadeOutDelay", MapScreen_set_mapMarkerMovementFadeOutDelay);
    registerSetter(L, "mapDragging", MapScreen_set_mapDragging);
    registerSetter(L, "mapMouseLastPosition", MapScreen_set_mapMouseLastPosition);
    registerSetter(L, "mapOffsetView", MapScreen_set_mapOffsetView);
    registerSetter(L, "worldSize", MapScreen_set_worldSize);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua