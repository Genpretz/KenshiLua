#include "pch.h"
#include "Hooks_Common.h"
#include <kenshi/gui/MapScreen.h>

// ---------------------------------------------------------------------------
// Hooks for MapScreen.h
//
// All address-bearing non-virtual members. Events fire after the original
// call except for destructors. Boolean results accept Lua overrides.
//
// Not hooked:
//   MapScreen::MapRoad::_CONSTRUCTOR
//     declaration has no importable _CONSTRUCTOR export
// ---------------------------------------------------------------------------

#define MAP_VOID0(method, Callback) \
    static void (*MapScreen_##method##_orig)(MapScreen*) = NULL; \
    static void MapScreen_##method##_hook(MapScreen* thisptr) \
    { \
        MapScreen_##method##_orig(thisptr); \
        Callback(thisptr); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_##method, \
        "MapScreen::" #method, KenshiLib::GetRealAddress(&MapScreen::method), \
        MapScreen_##method##_hook, MapScreen_##method##_orig)

#define MAP_WIDGET(method, Callback) \
    static void (*MapScreen_##method##_orig)(MapScreen*, MyGUI::Widget*) = NULL; \
    static void MapScreen_##method##_hook(MapScreen* thisptr, MyGUI::Widget* sender) \
    { \
        MapScreen_##method##_orig(thisptr, sender); \
        Callback(thisptr, sender); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_##method, \
        "MapScreen::" #method, KenshiLib::GetRealAddress(&MapScreen::method), \
        MapScreen_##method##_hook, MapScreen_##method##_orig)

static MapScreen::MapMarkerTown* (*MapMarkerTown_CONSTRUCTOR_orig)(MapScreen::MapMarkerTown*, TownBase*, MapScreen*) = NULL;
static MapScreen::MapMarkerTown* MapMarkerTown_CONSTRUCTOR_hook(MapScreen::MapMarkerTown* thisptr, TownBase* town, MapScreen* mapScreen)
{
    MapScreen::MapMarkerTown* result = MapMarkerTown_CONSTRUCTOR_orig(thisptr, town, mapScreen);
    CallMapMarkerTownConstructedCallbacks(thisptr, town, mapScreen);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerTown_CONSTRUCTOR,
    "MapScreen::MapMarkerTown::_CONSTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::MapMarkerTown::_CONSTRUCTOR),
    MapMarkerTown_CONSTRUCTOR_hook, MapMarkerTown_CONSTRUCTOR_orig)

static void (*MapMarkerTown_DESTRUCTOR_orig)(MapScreen::MapMarkerTown*) = NULL;
static void MapMarkerTown_DESTRUCTOR_hook(MapScreen::MapMarkerTown* thisptr)
{
    CallMapMarkerTownDestructorCallbacks(thisptr);
    MapMarkerTown_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerTown_DESTRUCTOR,
    "MapScreen::MapMarkerTown::_DESTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::MapMarkerTown::_DESTRUCTOR),
    MapMarkerTown_DESTRUCTOR_hook, MapMarkerTown_DESTRUCTOR_orig)

static void (*MapMarkerTown_update_orig)(MapScreen::MapMarkerTown*, const MyGUI::IntPoint&, MapZoomLevel) = NULL;
static void MapMarkerTown_update_hook(MapScreen::MapMarkerTown* thisptr, const MyGUI::IntPoint& mapPosition, MapZoomLevel zoom)
{
    MapMarkerTown_update_orig(thisptr, mapPosition, zoom);
    CallMapMarkerTownUpdateCallbacks(thisptr, mapPosition, static_cast<int>(zoom));
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerTown_update,
    "MapScreen::MapMarkerTown::update", KenshiLib::GetRealAddress(&MapScreen::MapMarkerTown::update),
    MapMarkerTown_update_hook, MapMarkerTown_update_orig)

static void (*MapMarkerTown_setVisible_orig)(MapScreen::MapMarkerTown*, bool) = NULL;
static void MapMarkerTown_setVisible_hook(MapScreen::MapMarkerTown* thisptr, bool value)
{
    MapMarkerTown_setVisible_orig(thisptr, value);
    CallMapMarkerTownSetVisibleCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerTown_setVisible,
    "MapScreen::MapMarkerTown::setVisible", KenshiLib::GetRealAddress(&MapScreen::MapMarkerTown::setVisible),
    MapMarkerTown_setVisible_hook, MapMarkerTown_setVisible_orig)

static bool (*MapMarkerTown_getVisible_orig)(const MapScreen::MapMarkerTown*) = NULL;
static bool MapMarkerTown_getVisible_hook(const MapScreen::MapMarkerTown* thisptr)
{
    bool result = MapMarkerTown_getVisible_orig(thisptr);
    return CallMapMarkerTownGetVisibleCallbacks(const_cast<MapScreen::MapMarkerTown*>(thisptr), result);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerTown_getVisible,
    "MapScreen::MapMarkerTown::getVisible", KenshiLib::GetRealAddress(&MapScreen::MapMarkerTown::getVisible),
    MapMarkerTown_getVisible_hook, MapMarkerTown_getVisible_orig)

static MapScreen::MapMarkerCharacter* (*MapMarkerCharacter_CONSTRUCTOR_orig)(MapScreen::MapMarkerCharacter*, RootObjectBase*, MapScreen*) = NULL;
static MapScreen::MapMarkerCharacter* MapMarkerCharacter_CONSTRUCTOR_hook(MapScreen::MapMarkerCharacter* thisptr, RootObjectBase* character, MapScreen* mapScreen)
{
    MapScreen::MapMarkerCharacter* result = MapMarkerCharacter_CONSTRUCTOR_orig(thisptr, character, mapScreen);
    CallMapMarkerCharacterConstructedCallbacks(thisptr, character, mapScreen);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerCharacter_CONSTRUCTOR,
    "MapScreen::MapMarkerCharacter::_CONSTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::MapMarkerCharacter::_CONSTRUCTOR),
    MapMarkerCharacter_CONSTRUCTOR_hook, MapMarkerCharacter_CONSTRUCTOR_orig)

static void (*MapMarkerCharacter_DESTRUCTOR_orig)(MapScreen::MapMarkerCharacter*) = NULL;
static void MapMarkerCharacter_DESTRUCTOR_hook(MapScreen::MapMarkerCharacter* thisptr)
{
    CallMapMarkerCharacterDestructorCallbacks(thisptr);
    MapMarkerCharacter_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerCharacter_DESTRUCTOR,
    "MapScreen::MapMarkerCharacter::_DESTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::MapMarkerCharacter::_DESTRUCTOR),
    MapMarkerCharacter_DESTRUCTOR_hook, MapMarkerCharacter_DESTRUCTOR_orig)

static void (*MapMarkerCharacter_update_orig)(MapScreen::MapMarkerCharacter*, const MyGUI::IntPoint&) = NULL;
static void MapMarkerCharacter_update_hook(MapScreen::MapMarkerCharacter* thisptr, const MyGUI::IntPoint& mapPosition)
{
    MapMarkerCharacter_update_orig(thisptr, mapPosition);
    CallMapMarkerCharacterUpdateCallbacks(thisptr, mapPosition);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerCharacter_update,
    "MapScreen::MapMarkerCharacter::update", KenshiLib::GetRealAddress(&MapScreen::MapMarkerCharacter::update),
    MapMarkerCharacter_update_hook, MapMarkerCharacter_update_orig)

static void (*MapMarkerCharacter_setVisible_orig)(MapScreen::MapMarkerCharacter*, bool) = NULL;
static void MapMarkerCharacter_setVisible_hook(MapScreen::MapMarkerCharacter* thisptr, bool value)
{
    MapMarkerCharacter_setVisible_orig(thisptr, value);
    CallMapMarkerCharacterSetVisibleCallbacks(thisptr, value);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerCharacter_setVisible,
    "MapScreen::MapMarkerCharacter::setVisible", KenshiLib::GetRealAddress(&MapScreen::MapMarkerCharacter::setVisible),
    MapMarkerCharacter_setVisible_hook, MapMarkerCharacter_setVisible_orig)

static bool (*MapMarkerCharacter_getVisible_orig)(const MapScreen::MapMarkerCharacter*) = NULL;
static bool MapMarkerCharacter_getVisible_hook(const MapScreen::MapMarkerCharacter* thisptr)
{
    bool result = MapMarkerCharacter_getVisible_orig(thisptr);
    return CallMapMarkerCharacterGetVisibleCallbacks(const_cast<MapScreen::MapMarkerCharacter*>(thisptr), result);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapMarkerCharacter_getVisible,
    "MapScreen::MapMarkerCharacter::getVisible", KenshiLib::GetRealAddress(&MapScreen::MapMarkerCharacter::getVisible),
    MapMarkerCharacter_getVisible_hook, MapMarkerCharacter_getVisible_orig)

static MapScreen* (*MapScreen_CONSTRUCTOR_orig)(MapScreen*, ManagementScreen*) = NULL;
static MapScreen* MapScreen_CONSTRUCTOR_hook(MapScreen* thisptr, ManagementScreen* screen)
{
    MapScreen* result = MapScreen_CONSTRUCTOR_orig(thisptr, screen);
    CallMapScreenConstructedCallbacks(thisptr, screen);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_CONSTRUCTOR,
    "MapScreen::_CONSTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::_CONSTRUCTOR),
    MapScreen_CONSTRUCTOR_hook, MapScreen_CONSTRUCTOR_orig)

static void (*MapScreen_DESTRUCTOR_orig)(MapScreen*) = NULL;
static void MapScreen_DESTRUCTOR_hook(MapScreen* thisptr)
{
    CallMapScreenDestructorCallbacks(thisptr);
    MapScreen_DESTRUCTOR_orig(thisptr);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_DESTRUCTOR,
    "MapScreen::_DESTRUCTOR", KenshiLib::GetRealAddress(&MapScreen::_DESTRUCTOR),
    MapScreen_DESTRUCTOR_hook, MapScreen_DESTRUCTOR_orig)

MAP_VOID0(clear, CallMapScreenClearCallbacks)

static bool (*MapScreen_getVisible_orig)(const MapScreen*) = NULL;
static bool MapScreen_getVisible_hook(const MapScreen* thisptr)
{
    bool result = MapScreen_getVisible_orig(thisptr);
    return CallMapScreenGetVisibleCallbacks(const_cast<MapScreen*>(thisptr), result);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_getVisible,
    "MapScreen::getVisible", KenshiLib::GetRealAddress(&MapScreen::getVisible),
    MapScreen_getVisible_hook, MapScreen_getVisible_orig)

MAP_VOID0(centerCamera, CallMapScreenCenterCameraCallbacks)
MAP_VOID0(clearTempMarkers, CallMapScreenClearTempMarkersCallbacks)
MAP_VOID0(refresh, CallMapScreenRefreshCallbacks)
MAP_VOID0(update, CallMapScreenUpdateCallbacks)

#define MAP_SQUAD(method, Callback) \
    static void (*MapScreen_##method##_orig)(MapScreen*, Platoon*) = NULL; \
    static void MapScreen_##method##_hook(MapScreen* thisptr, Platoon* squad) \
    { \
        MapScreen_##method##_orig(thisptr, squad); \
        Callback(thisptr, squad); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_##method, \
        "MapScreen::" #method, KenshiLib::GetRealAddress(&MapScreen::method), \
        MapScreen_##method##_hook, MapScreen_##method##_orig)

MAP_SQUAD(addSquad, CallMapScreenAddSquadCallbacks)
MAP_SQUAD(removeSquad, CallMapScreenRemoveSquadCallbacks)
MAP_VOID0(hide, CallMapScreenHideCallbacks)

static void (*MapScreen_setMovementMarker_orig)(MapScreen*, const Ogre::Vector3&, float) = NULL;
static void MapScreen_setMovementMarker_hook(MapScreen* thisptr, const Ogre::Vector3& position, float time)
{
    MapScreen_setMovementMarker_orig(thisptr, position, time);
    CallMapScreenSetMovementMarkerCallbacks(thisptr, position, time);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_setMovementMarker,
    "MapScreen::setMovementMarker", KenshiLib::GetRealAddress(&MapScreen::setMovementMarker),
    MapScreen_setMovementMarker_hook, MapScreen_setMovementMarker_orig)

static void (*MapScreen_showRoads_orig)(MapScreen*, bool) = NULL;
static void MapScreen_showRoads_hook(MapScreen* thisptr, bool on)
{
    MapScreen_showRoads_orig(thisptr, on);
    CallMapScreenShowRoadsCallbacks(thisptr, on);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_showRoads,
    "MapScreen::showRoads", KenshiLib::GetRealAddress(&MapScreen::showRoads),
    MapScreen_showRoads_hook, MapScreen_showRoads_orig)

static void (*MapScreen_updatePlayerTownMapMarker_orig)(MapScreen*, const hand&) = NULL;
static void MapScreen_updatePlayerTownMapMarker_hook(MapScreen* thisptr, const hand& town)
{
    MapScreen_updatePlayerTownMapMarker_orig(thisptr, town);
    CallMapScreenUpdatePlayerTownMapMarkerCallbacks(thisptr, town);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_updatePlayerTownMapMarker,
    "MapScreen::updatePlayerTownMapMarker", KenshiLib::GetRealAddress(&MapScreen::updatePlayerTownMapMarker),
    MapScreen_updatePlayerTownMapMarker_hook, MapScreen_updatePlayerTownMapMarker_orig)

MAP_VOID0(updateZoom, CallMapScreenUpdateZoomCallbacks)
MAP_VOID0(updateCameraMarker, CallMapScreenUpdateCameraMarkerCallbacks)
MAP_VOID0(refreshTowns, CallMapScreenRefreshTownsCallbacks)
MAP_VOID0(refreshSquads, CallMapScreenRefreshSquadsCallbacks)

static void (*MapScreen_updateCharacterMarker_orig)(MapScreen*, RootObjectBase*) = NULL;
static void MapScreen_updateCharacterMarker_hook(MapScreen* thisptr, RootObjectBase* object)
{
    MapScreen_updateCharacterMarker_orig(thisptr, object);
    CallMapScreenUpdateCharacterMarkerCallbacks(thisptr, object);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_updateCharacterMarker,
    "MapScreen::updateCharacterMarker", KenshiLib::GetRealAddress(&MapScreen::updateCharacterMarker),
    MapScreen_updateCharacterMarker_hook, MapScreen_updateCharacterMarker_orig)

static bool (*MapScreen_getMouseWorldPosition_orig)(MapScreen*, Ogre::Vector3&) = NULL;
static bool MapScreen_getMouseWorldPosition_hook(MapScreen* thisptr, Ogre::Vector3& position)
{
    bool result = MapScreen_getMouseWorldPosition_orig(thisptr, position);
    return CallMapScreenGetMouseWorldPositionCallbacks(thisptr, position, result);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_getMouseWorldPosition,
    "MapScreen::getMouseWorldPosition", KenshiLib::GetRealAddress(&MapScreen::getMouseWorldPosition),
    MapScreen_getMouseWorldPosition_hook, MapScreen_getMouseWorldPosition_orig)

static MyGUI::IntPoint (*MapScreen_worldToMapCoords_orig)(MapScreen*, const Ogre::Vector3&) = NULL;
static MyGUI::IntPoint MapScreen_worldToMapCoords_hook(MapScreen* thisptr, const Ogre::Vector3& position)
{
    MyGUI::IntPoint result = MapScreen_worldToMapCoords_orig(thisptr, position);
    CallMapScreenWorldToMapCoordsCallbacks(thisptr, position, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_worldToMapCoords,
    "MapScreen::worldToMapCoords", KenshiLib::GetRealAddress(&MapScreen::worldToMapCoords),
    MapScreen_worldToMapCoords_hook, MapScreen_worldToMapCoords_orig)

static Ogre::Vector3 (*MapScreen_mapCoordsToWorld_orig)(MapScreen*, const MyGUI::IntPoint&) = NULL;
static Ogre::Vector3 MapScreen_mapCoordsToWorld_hook(MapScreen* thisptr, const MyGUI::IntPoint& point)
{
    Ogre::Vector3 result = MapScreen_mapCoordsToWorld_orig(thisptr, point);
    CallMapScreenMapCoordsToWorldCallbacks(thisptr, point, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_mapCoordsToWorld,
    "MapScreen::mapCoordsToWorld", KenshiLib::GetRealAddress(&MapScreen::mapCoordsToWorld),
    MapScreen_mapCoordsToWorld_hook, MapScreen_mapCoordsToWorld_orig)

static void (*MapScreen_mapMouseWheel_orig)(MapScreen*, MyGUI::Widget*, int) = NULL;
static void MapScreen_mapMouseWheel_hook(MapScreen* thisptr, MyGUI::Widget* sender, int rel)
{
    MapScreen_mapMouseWheel_orig(thisptr, sender, rel);
    CallMapScreenMapMouseWheelCallbacks(thisptr, sender, rel);
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_mapMouseWheel,
    "MapScreen::mapMouseWheel", KenshiLib::GetRealAddress(&MapScreen::mapMouseWheel),
    MapScreen_mapMouseWheel_hook, MapScreen_mapMouseWheel_orig)

#define MAP_MOUSE_BUTTON(method, Callback) \
    static void (*MapScreen_##method##_orig)(MapScreen*, MyGUI::Widget*, int, int, MyGUI::MouseButton) = NULL; \
    static void MapScreen_##method##_hook(MapScreen* thisptr, MyGUI::Widget* sender, int left, int top, MyGUI::MouseButton id) \
    { \
        MapScreen_##method##_orig(thisptr, sender, left, top, id); \
        Callback(thisptr, sender, left, top, id.getValue()); \
    } \
    DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_##method, \
        "MapScreen::" #method, KenshiLib::GetRealAddress(&MapScreen::method), \
        MapScreen_##method##_hook, MapScreen_##method##_orig)

MAP_MOUSE_BUTTON(mapMousePressed, CallMapScreenMapMousePressedCallbacks)
MAP_MOUSE_BUTTON(mapMouseReleased, CallMapScreenMapMouseReleasedCallbacks)
MAP_VOID0(setupRoads, CallMapScreenSetupRoadsCallbacks)
MAP_VOID0(updateRoads, CallMapScreenUpdateRoadsCallbacks)
MAP_WIDGET(centerButton, CallMapScreenCenterButtonCallbacks)
MAP_WIDGET(zoomInButton, CallMapScreenZoomInButtonCallbacks)
MAP_WIDGET(zoomOutButton, CallMapScreenZoomOutButtonCallbacks)

static const MyGUI::Colour& (*MapScreen_getMarkerColor_orig)(RootObjectBase*) = NULL;
static const MyGUI::Colour& MapScreen_getMarkerColor_hook(RootObjectBase* who)
{
    const MyGUI::Colour& result = MapScreen_getMarkerColor_orig(who);
    CallMapScreenGetMarkerColorCallbacks(who, result);
    return result;
}
DEFINE_HOOK_INSTALLER(InstallHook_MapScreen_static_getMarkerColor,
    "MapScreen::getMarkerColor", KenshiLib::GetRealAddress(&MapScreen::getMarkerColor),
    MapScreen_getMarkerColor_hook, MapScreen_getMarkerColor_orig)

#undef MAP_MOUSE_BUTTON
#undef MAP_SQUAD
#undef MAP_WIDGET
#undef MAP_VOID0
