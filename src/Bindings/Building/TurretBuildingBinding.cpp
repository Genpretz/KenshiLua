#include "pch.h"
#include <kenshi/Building/TurretBuilding.h>
#include "TurretBuildingBinding.h"
#include "UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TurretBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<TurretBuilding>(L, idx, TurretBuildingBinding::getMetatableName());
}

// --- Getters for TurretBuilding ---
static int TurretBuilding_get_gunClass(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->gunClass);
    return 1;
}

static int TurretBuilding_get_aimDistInDegrees(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushnumber(L, instance->aimDistInDegrees);
    return 1;
}

static int TurretBuilding_get_currentAimDir(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    pushVector3(L, instance->currentAimDir);
    return 1;
}

static int TurretBuilding_get_rootAimDir(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    pushVector3(L, instance->rootAimDir);
    return 1;
}

static int TurretBuilding_get_currentAimSpeed(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushnumber(L, instance->currentAimSpeed);
    return 1;
}

static int TurretBuilding_get_currentAimTarget(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    pushVector3(L, instance->currentAimTarget);
    return 1;
}

static int TurretBuilding_get_mountedBuilding(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    // TODO: Unsupported type for mountedBuilding (hand)
    lua_pushnil(L);
    return 1;
}

static int TurretBuilding_get_hingePart(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->hingePart);
    return 1;
}

static int TurretBuilding_get_gunPart(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->gunPart);
    return 1;
}

static int TurretBuilding_get_aimTargetPos(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    pushVector3(L, instance->aimTargetPos);
    return 1;
}

static int TurretBuilding_get_rotating(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    lua_pushinteger(L, instance->rotating);
    return 1;
}

// --- Setters for TurretBuilding ---
static int TurretBuilding_set_gunClass(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gunClass");
}

static int TurretBuilding_set_aimDistInDegrees(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    instance->aimDistInDegrees = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TurretBuilding_set_currentAimDir(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    readVector3(L, 2, instance->currentAimDir);
    return 0;
}

static int TurretBuilding_set_rootAimDir(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    readVector3(L, 2, instance->rootAimDir);
    return 0;
}

static int TurretBuilding_set_currentAimSpeed(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    instance->currentAimSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int TurretBuilding_set_currentAimTarget(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    readVector3(L, 2, instance->currentAimTarget);
    return 0;
}

static int TurretBuilding_set_mountedBuilding(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mountedBuilding");
}

static int TurretBuilding_set_hingePart(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for hingePart");
}

static int TurretBuilding_set_gunPart(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for gunPart");
}

static int TurretBuilding_set_aimTargetPos(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    readVector3(L, 2, instance->aimTargetPos);
    return 0;
}

static int TurretBuilding_set_rotating(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");
    instance->rotating = (int)luaL_checkinteger(L, 2);
    return 0;
}

// --- Methods for TurretBuilding ---
int TurretBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TurretBuildingBinding::getDefaultTask(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    TaskType result = instance->getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TurretBuildingBinding::_NV_getDefaultTask(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    TaskType result = instance->_NV_getDefaultTask();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TurretBuildingBinding::setup(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->setup();
    return 0;
}

int TurretBuildingBinding::_NV_setup(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_setup();
    return 0;
}

int TurretBuildingBinding::update(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->update();
    return 0;
}

int TurretBuildingBinding::_NV_update(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_update();
    return 0;
}

int TurretBuildingBinding::needsUpdate(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::getStatUsed(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    StatsEnumerated result = instance->getStatUsed();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int TurretBuildingBinding::getProductionMultForGUI(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    float result = instance->getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::_NV_getProductionMultForGUI(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    float result = instance->_NV_getProductionMultForGUI();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::aimAt(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    Ogre::Vector3 who;
    readVector3(L, 2, who);
    instance->aimAt(who);
    return 0;
}

int TurretBuildingBinding::setVisible(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int TurretBuildingBinding::_NV_setVisible(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int TurretBuildingBinding::amInsideTownWalls(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    int result = instance->amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int TurretBuildingBinding::_NV_amInsideTownWalls(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    int result = instance->_NV_amInsideTownWalls();
    lua_pushinteger(L, result);
    return 1;
}

int TurretBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->notifyConstructionComplete();
    return 0;
}

int TurretBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_notifyConstructionComplete();
    return 0;
}

int TurretBuildingBinding::createPhysical(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::_NV_createPhysical(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TurretBuildingBinding::destroyPhysical(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->destroyPhysical();
    return 0;
}

int TurretBuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int TurretBuildingBinding::onBuildingLoaded(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->onBuildingLoaded();
    return 0;
}

int TurretBuildingBinding::_NV_onBuildingLoaded(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_onBuildingLoaded();
    return 0;
}

int TurretBuildingBinding::calculatePowerMult(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    float result = instance->calculatePowerMult();
    lua_pushnumber(L, result);
    return 1;
}

int TurretBuildingBinding::_teleport(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    instance->_teleport(p);
    return 0;
}

int TurretBuildingBinding::clearTownBuildingsManagerPtr(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->clearTownBuildingsManagerPtr();
    return 0;
}

int TurretBuildingBinding::_NV_clearTownBuildingsManagerPtr(lua_State* L)
{
    TurretBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TurretBuilding is nil");

    instance->_NV_clearTownBuildingsManagerPtr();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 13: TurretBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 24: void operate(...) - unsupported arg type
  line 25: void _NV_operate(...) - unsupported arg type
  line 29: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 30: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
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
  line 67: void setPartVisible(...) - unsupported arg type
  line 68: void _NV_setPartVisible(...) - unsupported arg type
*/

int TurretBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TurretBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TurretBuilding object");
    return 1;
}

void TurretBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TurretBuildingBinding::gc },
        { "__tostring", TurretBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TurretBuildingBinding::_DESTRUCTOR },
        { "getDefaultTask", TurretBuildingBinding::getDefaultTask },
        { "_NV_getDefaultTask", TurretBuildingBinding::_NV_getDefaultTask },
        { "setup", TurretBuildingBinding::setup },
        { "_NV_setup", TurretBuildingBinding::_NV_setup },
        { "update", TurretBuildingBinding::update },
        { "_NV_update", TurretBuildingBinding::_NV_update },
        { "needsUpdate", TurretBuildingBinding::needsUpdate },
        { "_NV_needsUpdate", TurretBuildingBinding::_NV_needsUpdate },
        { "getStatUsed", TurretBuildingBinding::getStatUsed },
        { "getProductionMultForGUI", TurretBuildingBinding::getProductionMultForGUI },
        { "_NV_getProductionMultForGUI", TurretBuildingBinding::_NV_getProductionMultForGUI },
        { "aimAt", TurretBuildingBinding::aimAt },
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
        { "_teleport", TurretBuildingBinding::_teleport },
        { "clearTownBuildingsManagerPtr", TurretBuildingBinding::clearTownBuildingsManagerPtr },
        { "_NV_clearTownBuildingsManagerPtr", TurretBuildingBinding::_NV_clearTownBuildingsManagerPtr },
        { 0, 0 }
    };

    registerClass(
        L, 
        TurretBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TurretBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TurretBuilding_get_gunClass);
    lua_setfield(L, -2, "gunClass");
    lua_pushcfunction(L, TurretBuilding_get_aimDistInDegrees);
    lua_setfield(L, -2, "aimDistInDegrees");
    lua_pushcfunction(L, TurretBuilding_get_currentAimDir);
    lua_setfield(L, -2, "currentAimDir");
    lua_pushcfunction(L, TurretBuilding_get_rootAimDir);
    lua_setfield(L, -2, "rootAimDir");
    lua_pushcfunction(L, TurretBuilding_get_currentAimSpeed);
    lua_setfield(L, -2, "currentAimSpeed");
    lua_pushcfunction(L, TurretBuilding_get_currentAimTarget);
    lua_setfield(L, -2, "currentAimTarget");
    lua_pushcfunction(L, TurretBuilding_get_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_pushcfunction(L, TurretBuilding_get_hingePart);
    lua_setfield(L, -2, "hingePart");
    lua_pushcfunction(L, TurretBuilding_get_gunPart);
    lua_setfield(L, -2, "gunPart");
    lua_pushcfunction(L, TurretBuilding_get_aimTargetPos);
    lua_setfield(L, -2, "aimTargetPos");
    lua_pushcfunction(L, TurretBuilding_get_rotating);
    lua_setfield(L, -2, "rotating");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TurretBuilding_set_gunClass);
    lua_setfield(L, -2, "gunClass");
    lua_pushcfunction(L, TurretBuilding_set_aimDistInDegrees);
    lua_setfield(L, -2, "aimDistInDegrees");
    lua_pushcfunction(L, TurretBuilding_set_currentAimDir);
    lua_setfield(L, -2, "currentAimDir");
    lua_pushcfunction(L, TurretBuilding_set_rootAimDir);
    lua_setfield(L, -2, "rootAimDir");
    lua_pushcfunction(L, TurretBuilding_set_currentAimSpeed);
    lua_setfield(L, -2, "currentAimSpeed");
    lua_pushcfunction(L, TurretBuilding_set_currentAimTarget);
    lua_setfield(L, -2, "currentAimTarget");
    lua_pushcfunction(L, TurretBuilding_set_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_pushcfunction(L, TurretBuilding_set_hingePart);
    lua_setfield(L, -2, "hingePart");
    lua_pushcfunction(L, TurretBuilding_set_gunPart);
    lua_setfield(L, -2, "gunPart");
    lua_pushcfunction(L, TurretBuilding_set_aimTargetPos);
    lua_setfield(L, -2, "aimTargetPos");
    lua_pushcfunction(L, TurretBuilding_set_rotating);
    lua_setfield(L, -2, "rotating");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // setMetatableParent(L, TurretBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
