#include "pch.h"
#include "Bindings/Building/FarmBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/FarmBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static FarmBuilding* getS(lua_State* L, int idx)
{
    return checkObject<FarmBuilding>(L, idx, FarmBuildingBinding::getMetatableName());
}

int FarmBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int FarmBuildingBinding::tostring(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int FarmBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, FarmBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    FarmBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO ogre_unordered_map<CropType, float>::type cropMultipliers; unsupported __index type from header line 66
    // TODO Ogre::SharedPtr<Ogre::Material> material; unsupported __index type from header line 141
    // TODO Ogre::Entity* plantEntity; unsupported __index type from header line 142
    // TODO lektor<FarmBuilding::Plant> plants; unsupported __index type from header line 143
    // TODO StaticBoxEntity* clickHull; unsupported __index type from header line 144
    if (strcmp(key, "batch") == 0) { lua_pushinteger(L, (lua_Integer)s->batch); return 1; }
    if (strcmp(key, "lastUpdated") == 0) { lua_pushnumber(L, s->lastUpdated); return 1; }
    if (strcmp(key, "eatingTime") == 0) { lua_pushnumber(L, s->eatingTime); return 1; }
    if (strcmp(key, "grown") == 0) { lua_pushnumber(L, s->grown); return 1; }
    if (strcmp(key, "died") == 0) { lua_pushnumber(L, s->died); return 1; }
    if (strcmp(key, "cleared") == 0) { lua_pushnumber(L, s->cleared); return 1; }
    if (strcmp(key, "growStart") == 0) { lua_pushnumber(L, s->growStart); return 1; }
    if (strcmp(key, "harvested") == 0) { lua_pushinteger(L, s->harvested); return 1; }
    if (strcmp(key, "itemsPerPlant") == 0) { lua_pushnumber(L, s->itemsPerPlant); return 1; }
    if (strcmp(key, "clearRate") == 0) { lua_pushnumber(L, s->clearRate); return 1; }
    if (strcmp(key, "consumptionRate") == 0) { lua_pushnumber(L, s->consumptionRate); return 1; }
    if (strcmp(key, "harvestRate") == 0) { lua_pushnumber(L, s->harvestRate); return 1; }
    if (strcmp(key, "growthTime") == 0) { lua_pushnumber(L, s->growthTime); return 1; }
    if (strcmp(key, "harvestTime") == 0) { lua_pushnumber(L, s->harvestTime); return 1; }
    if (strcmp(key, "deathTime") == 0) { lua_pushnumber(L, s->deathTime); return 1; }
    if (strcmp(key, "droughtTime") == 0) { lua_pushnumber(L, s->droughtTime); return 1; }
    if (strcmp(key, "deathThreshold") == 0) { lua_pushnumber(L, s->deathThreshold); return 1; }
    if (strcmp(key, "droughtMultiplier") == 0) { lua_pushnumber(L, s->droughtMultiplier); return 1; }
    if (strcmp(key, "fertilityMultiplier") == 0) { lua_pushnumber(L, s->fertilityMultiplier); return 1; }
    if (strcmp(key, "isHydroponic") == 0) { lua_pushboolean(L, s->isHydroponic ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int FarmBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    // TODO ogre_unordered_map<CropType, float>::type cropMultipliers; unsupported __newindex type from header line 66
    // TODO Ogre::SharedPtr<Ogre::Material> material; unsupported __newindex type from header line 141
    // TODO Ogre::Entity* plantEntity; unsupported __newindex type from header line 142
    // TODO lektor<FarmBuilding::Plant> plants; unsupported __newindex type from header line 143
    // TODO StaticBoxEntity* clickHull; unsupported __newindex type from header line 144
    // TODO FarmBuilding::FarmBatch* batch; unsupported __newindex type from header line 145
    if (strcmp(key, "lastUpdated") == 0) { s->lastUpdated = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "eatingTime") == 0) { s->eatingTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "grown") == 0) { s->grown = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "died") == 0) { s->died = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "cleared") == 0) { s->cleared = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "growStart") == 0) { s->growStart = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "harvested") == 0) { s->harvested = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "itemsPerPlant") == 0) { s->itemsPerPlant = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "clearRate") == 0) { s->clearRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "consumptionRate") == 0) { s->consumptionRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "harvestRate") == 0) { s->harvestRate = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "growthTime") == 0) { s->growthTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "harvestTime") == 0) { s->harvestTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "deathTime") == 0) { s->deathTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "droughtTime") == 0) { s->droughtTime = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "deathThreshold") == 0) { s->deathThreshold = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "droughtMultiplier") == 0) { s->droughtMultiplier = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "fertilityMultiplier") == 0) { s->fertilityMultiplier = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "isHydroponic") == 0) { s->isHydroponic = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int FarmBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int FarmBuildingBinding::createPhysical(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_createPhysical(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::destroyPhysical(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->destroyPhysical();
    return 0;
}

int FarmBuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->_NV_destroyPhysical();
    return 0;
}

int FarmBuildingBinding::setVisible(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->setVisible(on);
    return 0;
}

int FarmBuildingBinding::_NV_setVisible(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    s->_NV_setVisible(on);
    return 0;
}

int FarmBuildingBinding::update(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->update();
    return 0;
}

int FarmBuildingBinding::_NV_update(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->_NV_update();
    return 0;
}

int FarmBuildingBinding::needsUpdate(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isProductionFull(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    float result = s->howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::_NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    float result = s->_NV_howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->setupMiningResourceLevel();
    return 0;
}

int FarmBuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->_NV_setupMiningResourceLevel();
    return 0;
}

int FarmBuildingBinding::destroyAPlant(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->destroyAPlant();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::timeSkip(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    float h = (float)luaL_checknumber(L, 2);
    bool ignoreWater = lua_toboolean(L, 3) != 0;
    s->timeSkip(h, ignoreWater);
    return 0;
}

int FarmBuildingBinding::_updateInputs(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = s->_updateInputs(rate);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isCropsEdible(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->isCropsEdible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::eat(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->eat(rate);
    return 0;
}

int FarmBuildingBinding::dontNeedWorkRightNow(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    bool result = s->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::setupMaterial(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->setupMaterial();
    return 0;
}

int FarmBuildingBinding::updateMaterial(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->updateMaterial();
    return 0;
}

int FarmBuildingBinding::resetFarm(lua_State* L)
{
    FarmBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBuilding is nil");

    s->resetFarm();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 21: FarmBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 34: void operate(...) - unsupported arg type
  line 35: void _NV_operate(...) - unsupported arg type
  line 44: void getGUIData(...) - unsupported arg type
  line 45: void _NV_getGUIData(...) - unsupported arg type
  line 46: void getGUIEfficiency(...) - unsupported arg type
  line 47: void _NV_getGUIEfficiency(...) - unsupported arg type
  line 48: void getGUIWorkers(...) - unsupported arg type
  line 49: void _NV_getGUIWorkers(...) - unsupported arg type
  line 50: void getGUIState(...) - unsupported arg type
  line 51: void _NV_getGUIState(...) - unsupported arg type
  line 55: void upgrade(...) - unsupported arg type
  line 56: void _NV_upgrade(...) - unsupported arg type
  line 57: void downgrade(...) - unsupported arg type
  line 58: void _NV_downgrade(...) - unsupported arg type
  line 59: void getGUIFertility(...) - unsupported arg type
  line 60: void _NV_getGUIFertility(...) - unsupported arg type
  line 63: float getYieldChancePerCrop(...) - static method
  line 64: float getYieldChancePerCrop(...) - overloaded method
  line 65: float getCropMult(...) - unsupported arg type
  line 67: GameSaveState serialise(...) - unsupported return type
  line 68: GameSaveState _NV_serialise(...) - unsupported return type
  line 69: void loadFromSerialise(...) - unsupported arg type
  line 70: void _NV_loadFromSerialise(...) - unsupported arg type
  line 71: Ogre::Vector3 getDirectionMarker(...) - unsupported return type
  line 72: Ogre::Vector3 _NV_getDirectionMarker(...) - unsupported return type
  line 75: float getFertilityMultiplier(...) - static method
  line 149: void updatePlantInstance(...) - non-string reference arg
  line 150: void createPlants(...) - pointer arg
  line 151: void createClickHull(...) - pointer arg
  line 152: void createEntity(...) - pointer arg
*/

void FarmBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FarmBuildingBinding::gc },
        { "__tostring", FarmBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FarmBuildingBinding::_DESTRUCTOR },
        { "createPhysical", FarmBuildingBinding::createPhysical },
        { "_NV_createPhysical", FarmBuildingBinding::_NV_createPhysical },
        { "destroyPhysical", FarmBuildingBinding::destroyPhysical },
        { "_NV_destroyPhysical", FarmBuildingBinding::_NV_destroyPhysical },
        { "setVisible", FarmBuildingBinding::setVisible },
        { "_NV_setVisible", FarmBuildingBinding::_NV_setVisible },
        { "update", FarmBuildingBinding::update },
        { "_NV_update", FarmBuildingBinding::_NV_update },
        { "needsUpdate", FarmBuildingBinding::needsUpdate },
        { "_NV_needsUpdate", FarmBuildingBinding::_NV_needsUpdate },
        { "isAnyInputsEmpty", FarmBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", FarmBuildingBinding::_NV_isAnyInputsEmpty },
        { "isProductionFull", FarmBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", FarmBuildingBinding::_NV_isProductionFull },
        { "howMuchPowerDoYouWantForSortingFunction", FarmBuildingBinding::howMuchPowerDoYouWantForSortingFunction },
        { "_NV_howMuchPowerDoYouWantForSortingFunction", FarmBuildingBinding::_NV_howMuchPowerDoYouWantForSortingFunction },
        { "setupMiningResourceLevel", FarmBuildingBinding::setupMiningResourceLevel },
        { "_NV_setupMiningResourceLevel", FarmBuildingBinding::_NV_setupMiningResourceLevel },
        { "destroyAPlant", FarmBuildingBinding::destroyAPlant },
        { "timeSkip", FarmBuildingBinding::timeSkip },
        { "_updateInputs", FarmBuildingBinding::_updateInputs },
        { "isCropsEdible", FarmBuildingBinding::isCropsEdible },
        { "eat", FarmBuildingBinding::eat },
        { "dontNeedWorkRightNow", FarmBuildingBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", FarmBuildingBinding::_NV_dontNeedWorkRightNow },
        { "setupMaterial", FarmBuildingBinding::setupMaterial },
        { "updateMaterial", FarmBuildingBinding::updateMaterial },
        { "resetFarm", FarmBuildingBinding::resetFarm },
        { 0, 0 }
    };
    registerClass(L, FarmBuildingBinding::getMetatableName(), meta, methods, FarmBuildingBinding::index, FarmBuildingBinding::newindex);
}

} // namespace KenshiLua