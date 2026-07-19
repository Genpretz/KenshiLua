#include "pch.h"
#include <kenshi/Building/FarmBuilding.h>
#include "FarmBuildingBinding.h"
#include "ProductionBuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static FarmBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<FarmBuilding>(L, idx, FarmBuildingBinding::getMetatableName());
}

// --- Getters for FarmBuilding ---
static int FarmBuilding_get_cropMultipliers(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    // TODO: Unsupported type for cropMultipliers (ogre_unordered_map<CropType, float>::type)
    lua_pushnil(L);
    return 1;
}

static int FarmBuilding_get_material(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    // TODO: Unsupported type for material (Ogre::SharedPtr<Ogre::Material>)
    lua_pushnil(L);
    return 1;
}

static int FarmBuilding_get_plantEntity(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->plantEntity);
    return 1;
}

static int FarmBuilding_get_plants(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    // TODO: Unsupported type for plants (lektor<FarmBuilding::Plant>)
    lua_pushnil(L);
    return 1;
}

static int FarmBuilding_get_clickHull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->clickHull);
    return 1;
}

static int FarmBuilding_get_batch(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushlightuserdata(L, (void*)instance->batch);
    return 1;
}

static int FarmBuilding_get_lastUpdated(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->lastUpdated);
    return 1;
}

static int FarmBuilding_get_eatingTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->eatingTime);
    return 1;
}

static int FarmBuilding_get_grown(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->grown);
    return 1;
}

static int FarmBuilding_get_died(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->died);
    return 1;
}

static int FarmBuilding_get_cleared(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->cleared);
    return 1;
}

static int FarmBuilding_get_growStart(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->growStart);
    return 1;
}

static int FarmBuilding_get_harvested(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushinteger(L, instance->harvested);
    return 1;
}

static int FarmBuilding_get_itemsPerPlant(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->itemsPerPlant);
    return 1;
}

static int FarmBuilding_get_clearRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->clearRate);
    return 1;
}

static int FarmBuilding_get_consumptionRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->consumptionRate);
    return 1;
}

static int FarmBuilding_get_harvestRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->harvestRate);
    return 1;
}

static int FarmBuilding_get_growthTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->growthTime);
    return 1;
}

static int FarmBuilding_get_harvestTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->harvestTime);
    return 1;
}

static int FarmBuilding_get_deathTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->deathTime);
    return 1;
}

static int FarmBuilding_get_droughtTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->droughtTime);
    return 1;
}

static int FarmBuilding_get_deathThreshold(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->deathThreshold);
    return 1;
}

static int FarmBuilding_get_droughtMultiplier(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->droughtMultiplier);
    return 1;
}

static int FarmBuilding_get_fertilityMultiplier(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushnumber(L, instance->fertilityMultiplier);
    return 1;
}

static int FarmBuilding_get_isHydroponic(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lua_pushboolean(L, instance->isHydroponic ? 1 : 0);
    return 1;
}

// --- Setters for FarmBuilding ---
static int FarmBuilding_set_cropMultipliers(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for cropMultipliers");
}

static int FarmBuilding_set_material(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for material");
}

static int FarmBuilding_set_plantEntity(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for plantEntity");
}

static int FarmBuilding_set_plants(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for plants");
}

static int FarmBuilding_set_clickHull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for clickHull");
}

static int FarmBuilding_set_batch(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for batch");
}

static int FarmBuilding_set_lastUpdated(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->lastUpdated = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_eatingTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->eatingTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_grown(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->grown = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_died(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->died = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_cleared(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->cleared = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_growStart(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->growStart = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_harvested(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->harvested = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FarmBuilding_set_itemsPerPlant(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->itemsPerPlant = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_clearRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->clearRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_consumptionRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->consumptionRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_harvestRate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->harvestRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_growthTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->growthTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_harvestTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->harvestTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_deathTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->deathTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_droughtTime(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->droughtTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_deathThreshold(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->deathThreshold = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_droughtMultiplier(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->droughtMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_fertilityMultiplier(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->fertilityMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FarmBuilding_set_isHydroponic(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->isHydroponic = lua_toboolean(L, 2) != 0;
    return 0;
}

// --- Methods for FarmBuilding
int FarmBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FarmBuildingBinding::createPhysical(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_createPhysical(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::destroyPhysical(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->destroyPhysical();
    return 0;
}

int FarmBuildingBinding::_NV_destroyPhysical(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->_NV_destroyPhysical();
    return 0;
}

int FarmBuildingBinding::setVisible(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int FarmBuildingBinding::_NV_setVisible(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->_NV_setVisible(on);
    return 0;
}

int FarmBuildingBinding::update(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->update();
    return 0;
}

int FarmBuildingBinding::_NV_update(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->_NV_update();
    return 0;
}

int FarmBuildingBinding::needsUpdate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_needsUpdate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->_NV_needsUpdate();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isProductionFull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_isProductionFull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->_NV_isProductionFull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    float result = instance->howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::_NV_howMuchPowerDoYouWantForSortingFunction(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    float result = instance->_NV_howMuchPowerDoYouWantForSortingFunction();
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::setupMiningResourceLevel(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->setupMiningResourceLevel();
    return 0;
}

int FarmBuildingBinding::_NV_setupMiningResourceLevel(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->_NV_setupMiningResourceLevel();
    return 0;
}

int FarmBuildingBinding::destroyAPlant(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->destroyAPlant();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::timeSkip(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    float h = (float)luaL_checknumber(L, 2);
    bool ignoreWater = lua_toboolean(L, 3) != 0;
    instance->timeSkip(h, ignoreWater);
    return 0;
}

int FarmBuildingBinding::_updateInputs(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    bool result = instance->_updateInputs(rate);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::isCropsEdible(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->isCropsEdible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::eat(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    instance->eat(rate);
    return 0;
}

int FarmBuildingBinding::getDirectionMarker(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->getDirectionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int FarmBuildingBinding::_NV_getDirectionMarker(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->_NV_getDirectionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int FarmBuildingBinding::dontNeedWorkRightNow(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    bool result = instance->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FarmBuildingBinding::setupMaterial(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->setupMaterial();
    return 0;
}

int FarmBuildingBinding::updateMaterial(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->updateMaterial();
    return 0;
}

int FarmBuildingBinding::resetFarm(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    instance->resetFarm();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 21: FarmBuilding* _CONSTRUCTOR(...) - unsupported arg type
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
  line 75: float getFertilityMultiplier(...) - static method
  line 149: void updatePlantInstance(...) - non-string reference arg
  line 150: void createPlants(...) - pointer arg
  line 151: void createClickHull(...) - pointer arg
  line 152: void createEntity(...) - pointer arg
*/

int FarmBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FarmBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBuilding object");
    return 1;
}

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
        { "getDirectionMarker", FarmBuildingBinding::getDirectionMarker },
        { "_NV_getDirectionMarker", FarmBuildingBinding::_NV_getDirectionMarker },
        { "dontNeedWorkRightNow", FarmBuildingBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", FarmBuildingBinding::_NV_dontNeedWorkRightNow },
        { "setupMaterial", FarmBuildingBinding::setupMaterial },
        { "updateMaterial", FarmBuildingBinding::updateMaterial },
        { "resetFarm", FarmBuildingBinding::resetFarm },
        { 0, 0 }
    };

    registerClass(
        L, 
        FarmBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FarmBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FarmBuilding_get_cropMultipliers);
    lua_setfield(L, -2, "cropMultipliers");
    lua_pushcfunction(L, FarmBuilding_get_material);
    lua_setfield(L, -2, "material");
    lua_pushcfunction(L, FarmBuilding_get_plantEntity);
    lua_setfield(L, -2, "plantEntity");
    lua_pushcfunction(L, FarmBuilding_get_plants);
    lua_setfield(L, -2, "plants");
    lua_pushcfunction(L, FarmBuilding_get_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_pushcfunction(L, FarmBuilding_get_batch);
    lua_setfield(L, -2, "batch");
    lua_pushcfunction(L, FarmBuilding_get_lastUpdated);
    lua_setfield(L, -2, "lastUpdated");
    lua_pushcfunction(L, FarmBuilding_get_eatingTime);
    lua_setfield(L, -2, "eatingTime");
    lua_pushcfunction(L, FarmBuilding_get_grown);
    lua_setfield(L, -2, "grown");
    lua_pushcfunction(L, FarmBuilding_get_died);
    lua_setfield(L, -2, "died");
    lua_pushcfunction(L, FarmBuilding_get_cleared);
    lua_setfield(L, -2, "cleared");
    lua_pushcfunction(L, FarmBuilding_get_growStart);
    lua_setfield(L, -2, "growStart");
    lua_pushcfunction(L, FarmBuilding_get_harvested);
    lua_setfield(L, -2, "harvested");
    lua_pushcfunction(L, FarmBuilding_get_itemsPerPlant);
    lua_setfield(L, -2, "itemsPerPlant");
    lua_pushcfunction(L, FarmBuilding_get_clearRate);
    lua_setfield(L, -2, "clearRate");
    lua_pushcfunction(L, FarmBuilding_get_consumptionRate);
    lua_setfield(L, -2, "consumptionRate");
    lua_pushcfunction(L, FarmBuilding_get_harvestRate);
    lua_setfield(L, -2, "harvestRate");
    lua_pushcfunction(L, FarmBuilding_get_growthTime);
    lua_setfield(L, -2, "growthTime");
    lua_pushcfunction(L, FarmBuilding_get_harvestTime);
    lua_setfield(L, -2, "harvestTime");
    lua_pushcfunction(L, FarmBuilding_get_deathTime);
    lua_setfield(L, -2, "deathTime");
    lua_pushcfunction(L, FarmBuilding_get_droughtTime);
    lua_setfield(L, -2, "droughtTime");
    lua_pushcfunction(L, FarmBuilding_get_deathThreshold);
    lua_setfield(L, -2, "deathThreshold");
    lua_pushcfunction(L, FarmBuilding_get_droughtMultiplier);
    lua_setfield(L, -2, "droughtMultiplier");
    lua_pushcfunction(L, FarmBuilding_get_fertilityMultiplier);
    lua_setfield(L, -2, "fertilityMultiplier");
    lua_pushcfunction(L, FarmBuilding_get_isHydroponic);
    lua_setfield(L, -2, "isHydroponic");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FarmBuilding_set_cropMultipliers);
    lua_setfield(L, -2, "cropMultipliers");
    lua_pushcfunction(L, FarmBuilding_set_material);
    lua_setfield(L, -2, "material");
    lua_pushcfunction(L, FarmBuilding_set_plantEntity);
    lua_setfield(L, -2, "plantEntity");
    lua_pushcfunction(L, FarmBuilding_set_plants);
    lua_setfield(L, -2, "plants");
    lua_pushcfunction(L, FarmBuilding_set_clickHull);
    lua_setfield(L, -2, "clickHull");
    lua_pushcfunction(L, FarmBuilding_set_batch);
    lua_setfield(L, -2, "batch");
    lua_pushcfunction(L, FarmBuilding_set_lastUpdated);
    lua_setfield(L, -2, "lastUpdated");
    lua_pushcfunction(L, FarmBuilding_set_eatingTime);
    lua_setfield(L, -2, "eatingTime");
    lua_pushcfunction(L, FarmBuilding_set_grown);
    lua_setfield(L, -2, "grown");
    lua_pushcfunction(L, FarmBuilding_set_died);
    lua_setfield(L, -2, "died");
    lua_pushcfunction(L, FarmBuilding_set_cleared);
    lua_setfield(L, -2, "cleared");
    lua_pushcfunction(L, FarmBuilding_set_growStart);
    lua_setfield(L, -2, "growStart");
    lua_pushcfunction(L, FarmBuilding_set_harvested);
    lua_setfield(L, -2, "harvested");
    lua_pushcfunction(L, FarmBuilding_set_itemsPerPlant);
    lua_setfield(L, -2, "itemsPerPlant");
    lua_pushcfunction(L, FarmBuilding_set_clearRate);
    lua_setfield(L, -2, "clearRate");
    lua_pushcfunction(L, FarmBuilding_set_consumptionRate);
    lua_setfield(L, -2, "consumptionRate");
    lua_pushcfunction(L, FarmBuilding_set_harvestRate);
    lua_setfield(L, -2, "harvestRate");
    lua_pushcfunction(L, FarmBuilding_set_growthTime);
    lua_setfield(L, -2, "growthTime");
    lua_pushcfunction(L, FarmBuilding_set_harvestTime);
    lua_setfield(L, -2, "harvestTime");
    lua_pushcfunction(L, FarmBuilding_set_deathTime);
    lua_setfield(L, -2, "deathTime");
    lua_pushcfunction(L, FarmBuilding_set_droughtTime);
    lua_setfield(L, -2, "droughtTime");
    lua_pushcfunction(L, FarmBuilding_set_deathThreshold);
    lua_setfield(L, -2, "deathThreshold");
    lua_pushcfunction(L, FarmBuilding_set_droughtMultiplier);
    lua_setfield(L, -2, "droughtMultiplier");
    lua_pushcfunction(L, FarmBuilding_set_fertilityMultiplier);
    lua_setfield(L, -2, "fertilityMultiplier");
    lua_pushcfunction(L, FarmBuilding_set_isHydroponic);
    lua_setfield(L, -2, "isHydroponic");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ProductionBuilding
    // setMetatableParent(L, FarmBuildingBinding::getMetatableName(), ProductionBuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
