#include "pch.h"
#include "Bindings/Building/TurretBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/TurretBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static TurretBuilding* getS(lua_State* L, int idx)
{
    return checkObject<TurretBuilding>(L, idx, TurretBuildingBinding::getMetatableName());
}

int TurretBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int TurretBuildingBinding::tostring(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int TurretBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, TurretBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    TurretBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO GunClassTurret* gunClass; unsupported __index type from header line 61
    if (strcmp(key, "aimDistInDegrees") == 0) { lua_pushnumber(L, s->aimDistInDegrees); return 1; }
    // TODO Ogre::Vector3 currentAimDir; unsupported __index type from header line 63
    // TODO Ogre::Vector3 rootAimDir; unsupported __index type from header line 64
    if (strcmp(key, "currentAimSpeed") == 0) { lua_pushnumber(L, s->currentAimSpeed); return 1; }
    // TODO Ogre::Vector3 currentAimTarget; unsupported __index type from header line 66
    // TODO hand mountedBuilding; unsupported __index type from header line 69
    if (strcmp(key, "hingePart") == 0) { lua_pushinteger(L, (lua_Integer)s->hingePart); return 1; }
    if (strcmp(key, "gunPart") == 0) { lua_pushinteger(L, (lua_Integer)s->gunPart); return 1; }
    // TODO Ogre::Vector3 aimTargetPos; unsupported __index type from header line 72
    if (strcmp(key, "rotating") == 0) { lua_pushinteger(L, s->rotating); return 1; }

    lua_pushnil(L);
    return 1;
}

int TurretBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    // TODO GunClassTurret* gunClass; unsupported __newindex type from header line 61
    if (strcmp(key, "aimDistInDegrees") == 0) { s->aimDistInDegrees = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Ogre::Vector3 currentAimDir; unsupported __newindex type from header line 63
    // TODO Ogre::Vector3 rootAimDir; unsupported __newindex type from header line 64
    if (strcmp(key, "currentAimSpeed") == 0) { s->currentAimSpeed = (float)luaL_checknumber(L, 3); return 0; }
    // TODO Ogre::Vector3 currentAimTarget; unsupported __newindex type from header line 66
    // TODO hand mountedBuilding; unsupported __newindex type from header line 69
    // TODO PhysicsCollection::RotatingEnt* hingePart; unsupported __newindex type from header line 70
    // TODO PhysicsCollection::RotatingEnt* gunPart; unsupported __newindex type from header line 71
    // TODO Ogre::Vector3 aimTargetPos; unsupported __newindex type from header line 72
    if (strcmp(key, "rotating") == 0) { s->rotating = (int)luaL_checkinteger(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int TurretBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int TurretBuildingBinding::setup(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->setup();
    return 0;
}

int TurretBuildingBinding::_NV_setup(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_setup();
    return 0;
}

int TurretBuildingBinding::update(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->update();
    return 0;
}

int TurretBuildingBinding::_NV_update(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_update();
    return 0;
}

int TurretBuildingBinding::needsUpdate(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool result = s->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool result = s->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::getProductionMultForGUI(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    float result = s->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    float result = s->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::setVisible(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setVisible(on);
    return 0;
}

int TurretBuildingBinding::_NV_setVisible(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_setVisible(on);
    return 0;
}

int TurretBuildingBinding::amInsideTownWalls(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    int result = s->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int TurretBuildingBinding::_NV_amInsideTownWalls(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    int result = s->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int TurretBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->notifyConstructionComplete();
    return 0;
}

int TurretBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_notifyConstructionComplete();
    return 0;
}

int TurretBuildingBinding::createPhysical(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool result = s->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::_NV_createPhysical(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    bool result = s->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::destroyPhysical(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->destroyPhysical();
    return 0;
}

int TurretBuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_destroyPhysical();
    return 0;
}

int TurretBuildingBinding::onBuildingLoaded(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->onBuildingLoaded();
    return 0;
}

int TurretBuildingBinding::_NV_onBuildingLoaded(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_onBuildingLoaded();
    return 0;
}

int TurretBuildingBinding::calculatePowerMult(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    float result = s->calculatePowerMult();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::clearTownBuildingsManagerPtr(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->clearTownBuildingsManagerPtr();
    return 0;
}

int TurretBuildingBinding::_NV_clearTownBuildingsManagerPtr(lua_State* L)
{
    TurretBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TurretBuilding is nil");

    s->_NV_clearTownBuildingsManagerPtr();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 13: TurretBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 16: TaskType getDefaultTask(...) - unsupported return type
  line 17: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 24: void operate(...) - unsupported arg type
  line 25: void _NV_operate(...) - unsupported arg type
  line 26: StatsEnumerated getStatUsed(...) - unsupported return type
  line 29: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 30: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 31: void aimAt(...) - unsupported arg type
  line 34: void setMountedBuilding(...) - unsupported arg type
  line 35: const hand& getMountedBuilding(...) - reference return type
  line 36: const hand& _NV_getMountedBuilding(...) - reference return type
  line 47: void addToBuildingsMananger(...) - unsupported arg type
  line 48: void removeFromBuildingsMananger(...) - unsupported arg type
  line 49: void getGUIState(...) - unsupported arg type
  line 50: void _NV_getGUIState(...) - unsupported arg type
  line 51: void getGUIData(...) - unsupported arg type
  line 52: void _NV_getGUIData(...) - unsupported arg type
  line 53: GameSaveState serialise(...) - unsupported return type
  line 54: GameSaveState _NV_serialise(...) - unsupported return type
  line 55: void loadFromSerialise(...) - unsupported arg type
  line 56: void _NV_loadFromSerialise(...) - unsupported arg type
  line 58: void _teleport(...) - unsupported arg type
  line 67: void setPartVisible(...) - unsupported arg type
  line 68: void _NV_setPartVisible(...) - unsupported arg type
*/

void TurretBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TurretBuildingBinding::gc },
        { "__tostring", TurretBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TurretBuildingBinding::_DESTRUCTOR },
        { "setup", TurretBuildingBinding::setup },
        { "_NV_setup", TurretBuildingBinding::_NV_setup },
        { "update", TurretBuildingBinding::update },
        { "_NV_update", TurretBuildingBinding::_NV_update },
        { "needsUpdate", TurretBuildingBinding::needsUpdate },
        { "_NV_needsUpdate", TurretBuildingBinding::_NV_needsUpdate },
        { "getProductionMultForGUI", TurretBuildingBinding::getProductionMultForGUI },
        { "_NV_getProductionMultForGUI", TurretBuildingBinding::_NV_getProductionMultForGUI },
        { "setVisible", TurretBuildingBinding::setVisible },
        { "_NV_setVisible", TurretBuildingBinding::_NV_setVisible },
        { "amInsideTownWalls", TurretBuildingBinding::amInsideTownWalls },
        { "_NV_amInsideTownWalls", TurretBuildingBinding::_NV_amInsideTownWalls },
        { "notifyConstructionComplete", TurretBuildingBinding::notifyConstructionComplete },
        { "_NV_notifyConstructionComplete", TurretBuildingBinding::_NV_notifyConstructionComplete },
        { "createPhysical", TurretBuildingBinding::createPhysical },
        { "_NV_createPhysical", TurretBuildingBinding::_NV_createPhysical },
        { "destroyPhysical", TurretBuildingBinding::destroyPhysical },
        { "_NV_destroyPhysical", TurretBuildingBinding::_NV_destroyPhysical },
        { "onBuildingLoaded", TurretBuildingBinding::onBuildingLoaded },
        { "_NV_onBuildingLoaded", TurretBuildingBinding::_NV_onBuildingLoaded },
        { "calculatePowerMult", TurretBuildingBinding::calculatePowerMult },
        { "clearTownBuildingsManagerPtr", TurretBuildingBinding::clearTownBuildingsManagerPtr },
        { "_NV_clearTownBuildingsManagerPtr", TurretBuildingBinding::_NV_clearTownBuildingsManagerPtr },
        { 0, 0 }
    };
    registerClass(L, TurretBuildingBinding::getMetatableName(), meta, methods, TurretBuildingBinding::index, TurretBuildingBinding::newindex);
}

} // namespace KenshiLua