#include "pch.h"
class Layout {};
class AreaBiomeGroup {};
class PosRotPair {};
class StaticBoxEntity {};
#include "Bindings/Building/FarmBuildingBinding.h"
#include "Bindings/Building/ProductionBuildingBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Building/FarmBatchBinding.h"
#include "Bindings/FarmBuilding_PlantBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"
#include "Lua/BindingHelpers.h"
#include <kenshi/GameSaveState.h>

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
    return pushObject<ogre_unordered_map<CropType, float>::type>(
        L, &instance->cropMultipliers, OgreUnorderedMapBinding<CropType, float>::getMetatableName());
}

static int FarmBuilding_get_material(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    if (instance->material.get()) {
        lua_pushlightuserdata(L, (void*)instance->material.get());
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int FarmBuilding_get_plantEntity(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    if (instance->plantEntity) {
        lua_pushlightuserdata(L, (void*)instance->plantEntity);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int FarmBuilding_get_plants(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return pushObject<lektor<FarmBuilding::Plant>>(L, &instance->plants, LektorValueBinding<FarmBuilding::Plant>::metaName);
}

static int FarmBuilding_get_clickHull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    if (instance->clickHull) {
        lua_pushlightuserdata(L, (void*)instance->clickHull);
    } else {
        lua_pushnil(L);
    }
    return 1;
}

static int FarmBuilding_get_batch(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return pushObject<FarmBuilding::FarmBatch>(L, instance->batch, FarmBatchBinding::getMetatableName());
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
    ogre_unordered_map<CropType, float>::type* val = OgreUnorderedMapBinding<CropType, float>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'cropMultipliers' must be ogre_unordered_map<CropType, float>");
    instance->cropMultipliers = *val;
    return 0;
}

static int FarmBuilding_set_material(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    return luaL_error(L, "Property '%s' is read-only or does not exist", lua_tostring(L, 2));
}

static int FarmBuilding_set_plantEntity(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->plantEntity = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}

static int FarmBuilding_set_plants(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    lektor<FarmBuilding::Plant>* val = LektorValueBinding<FarmBuilding::Plant>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'plants' must be lektor<FarmBuilding::Plant>");
    instance->plants = *val;
    return 0;
}

static int FarmBuilding_set_clickHull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->clickHull = (StaticBoxEntity*)lua_touserdata(L, 2);
    return 0;
}

static int FarmBuilding_set_batch(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    instance->batch = lua_isnoneornil(L, 2) ? nullptr : checkObject<FarmBuilding::FarmBatch>(L, 2, FarmBatchBinding::getMetatableName());
    return 0;
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
int FarmBuildingBinding::_CONSTRUCTOR(lua_State* L)
{
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Ogre::Vector3 position;
    readVector3(L, 3, position);
    Ogre::Quaternion orientation;
    readQuaternion(L, 4, orientation);
    Faction* _participant = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    hand* town = checkObject<hand>(L, 6, HandBinding::getMetatableName());
    hand* _handle = checkObject<hand>(L, 7, HandBinding::getMetatableName());
    Layout* __isfurnitureOf = (Layout*)lua_touserdata(L, 8);
    Building* _indoors = lua_isnoneornil(L, 9) ? nullptr : checkObject<Building>(L, 9, BuildingBinding::getMetatableName());

    FarmBuilding* result = new FarmBuilding(data, position, orientation, _participant, *town, *_handle, __isfurnitureOf, _indoors);
    return pushObject<FarmBuilding>(L, result, FarmBuildingBinding::getMetatableName());
}

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

int FarmBuildingBinding::operate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->operate(who, amount);
    return 0;
}

int FarmBuildingBinding::_NV_operate(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    Character* who = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->_NV_operate(who, amount);
    return 0;
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

int FarmBuildingBinding::getGUIData(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(datapanel, category);
    return 0;
}

int FarmBuildingBinding::_NV_getGUIData(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIData(datapanel, category);
    return 0;
}

int FarmBuildingBinding::getGUIEfficiency(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIEfficiency(datapanel, category);
    return 0;
}

int FarmBuildingBinding::_NV_getGUIEfficiency(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIEfficiency(datapanel, category);
    return 0;
}

int FarmBuildingBinding::getGUIWorkers(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIWorkers(datapanel, category);
    return 0;
}

int FarmBuildingBinding::_NV_getGUIWorkers(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIWorkers(datapanel, category);
    return 0;
}

int FarmBuildingBinding::getGUIState(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIState(datapanel, category);
    return 0;
}

int FarmBuildingBinding::_NV_getGUIState(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIState(datapanel, category);
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

int FarmBuildingBinding::upgrade(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->upgrade(line);
    return 0;
}

int FarmBuildingBinding::_NV_upgrade(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_upgrade(line);
    return 0;
}

int FarmBuildingBinding::downgrade(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->downgrade(line);
    return 0;
}

int FarmBuildingBinding::_NV_downgrade(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DataPanelLine* line = checkObject<DataPanelLine>(L, 2, DataPanelLineBinding::getMetatableName());
    instance->_NV_downgrade(line);
    return 0;
}

int FarmBuildingBinding::getGUIFertility(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIFertility(datapanel, category);
    return 0;
}

int FarmBuildingBinding::_NV_getGUIFertility(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    DatapanelGUI* datapanel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->_NV_getGUIFertility(datapanel, category);
    return 0;
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

int FarmBuildingBinding::getYieldChancePerCrop(lua_State* L)
{
    if (lua_gettop(L) >= 4) {
        GameData* farmData = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
        AreaBiomeGroup* biome = (AreaBiomeGroup*)lua_touserdata(L, 2);
        float skillMult = (float)luaL_checknumber(L, 3);
        float resourceMult = (float)luaL_checknumber(L, 4);
        float result = FarmBuilding::getYieldChancePerCrop(farmData, biome, skillMult, resourceMult);
        lua_pushnumber(L, result);
        return 1;
    }
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");
    float skillMult = (float)luaL_checknumber(L, 2);
    float result = instance->getYieldChancePerCrop(skillMult);
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::getCropMult(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    CropType typ = (CropType)luaL_checkinteger(L, 2);
    float result = instance->getCropMult(typ);
    lua_pushnumber(L, result);
    return 1;
}

int FarmBuildingBinding::serialise(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->serialise(container, refList, offsetPosToSubtract);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int FarmBuildingBinding::_NV_serialise(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->_NV_serialise(container, refList, offsetPosToSubtract);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int FarmBuildingBinding::loadFromSerialise(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    GameSaveState* stateList = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(stateList);
    return 0;
}

int FarmBuildingBinding::_NV_loadFromSerialise(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    GameSaveState* stateList = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(stateList);
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

int FarmBuildingBinding::getFertilityMultiplier(lua_State* L)
{
    float resourceLevel = (float)luaL_checknumber(L, 1);
    GameData* farmData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    float result = FarmBuilding::getFertilityMultiplier(resourceLevel, farmData);
    lua_pushnumber(L, result);
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

int FarmBuildingBinding::updatePlantInstance(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    FarmBuilding::Plant* p = checkObject<FarmBuilding::Plant>(L, 2, FarmBuilding_PlantBinding::getMetatableName());
    instance->updatePlantInstance(*p);
    return 0;
}

int FarmBuildingBinding::createPlants(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    FarmBuilding::FarmBatch* batch = checkObject<FarmBuilding::FarmBatch>(L, 2, FarmBatchBinding::getMetatableName());
    instance->createPlants(batch);
    return 0;
}

int FarmBuildingBinding::createClickHull(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    FarmBuilding::FarmBatch* batch = checkObject<FarmBuilding::FarmBatch>(L, 2, FarmBatchBinding::getMetatableName());
    instance->createClickHull(batch);
    return 0;
}

int FarmBuildingBinding::createEntity(lua_State* L)
{
    FarmBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FarmBuilding is nil");

    FarmBuilding::FarmBatch* batch = checkObject<FarmBuilding::FarmBatch>(L, 2, FarmBatchBinding::getMetatableName());
    instance->createEntity(batch);
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
LIGHTUSERDATA DEPENDENCIES:
  - FarmBuildingBinding::_CONSTRUCTOR: Layout* __isfurnitureOf (unbound pointer)
  - FarmBuilding_get_material / FarmBuilding_set_material: Ogre::SharedPtr<Ogre::Material> (unbound smart-pointer type)
  - FarmBuilding_get_plantEntity / FarmBuilding_set_plantEntity: Ogre::Entity* (unbound pointer)
  - FarmBuilding_get_clickHull / FarmBuilding_set_clickHull: StaticBoxEntity* (unbound pointer)
  - FarmBuildingBinding::getYieldChancePerCrop: AreaBiomeGroup* biome (unbound pointer)
*/

int FarmBuildingBinding::gc(lua_State* L)
{
    return 0;
}

int FarmBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FarmBuilding object");
    return 1;
}

void FarmBuildingBinding::registerBinding(lua_State* L)
{
    OgreUnorderedMapBinding<CropType, float>::registerBinding(L, "ogre_unordered_map<CropType, float>", nullptr, nullptr);

    static const luaL_Reg meta[] = {
        { "__gc",       FarmBuildingBinding::gc },
        { "__tostring", FarmBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FarmBuildingBinding::_CONSTRUCTOR },
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
        { "operate", FarmBuildingBinding::operate },
        { "_NV_operate", FarmBuildingBinding::_NV_operate },
        { "isAnyInputsEmpty", FarmBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", FarmBuildingBinding::_NV_isAnyInputsEmpty },
        { "isProductionFull", FarmBuildingBinding::isProductionFull },
        { "_NV_isProductionFull", FarmBuildingBinding::_NV_isProductionFull },
        { "howMuchPowerDoYouWantForSortingFunction", FarmBuildingBinding::howMuchPowerDoYouWantForSortingFunction },
        { "_NV_howMuchPowerDoYouWantForSortingFunction", FarmBuildingBinding::_NV_howMuchPowerDoYouWantForSortingFunction },
        { "setupMiningResourceLevel", FarmBuildingBinding::setupMiningResourceLevel },
        { "_NV_setupMiningResourceLevel", FarmBuildingBinding::_NV_setupMiningResourceLevel },
        { "getGUIData", FarmBuildingBinding::getGUIData },
        { "_NV_getGUIData", FarmBuildingBinding::_NV_getGUIData },
        { "getGUIEfficiency", FarmBuildingBinding::getGUIEfficiency },
        { "_NV_getGUIEfficiency", FarmBuildingBinding::_NV_getGUIEfficiency },
        { "getGUIWorkers", FarmBuildingBinding::getGUIWorkers },
        { "_NV_getGUIWorkers", FarmBuildingBinding::_NV_getGUIWorkers },
        { "getGUIState", FarmBuildingBinding::getGUIState },
        { "_NV_getGUIState", FarmBuildingBinding::_NV_getGUIState },
        { "destroyAPlant", FarmBuildingBinding::destroyAPlant },
        { "timeSkip", FarmBuildingBinding::timeSkip },
        { "_updateInputs", FarmBuildingBinding::_updateInputs },
        { "upgrade", FarmBuildingBinding::upgrade },
        { "_NV_upgrade", FarmBuildingBinding::_NV_upgrade },
        { "downgrade", FarmBuildingBinding::downgrade },
        { "_NV_downgrade", FarmBuildingBinding::_NV_downgrade },
        { "getGUIFertility", FarmBuildingBinding::getGUIFertility },
        { "_NV_getGUIFertility", FarmBuildingBinding::_NV_getGUIFertility },
        { "isCropsEdible", FarmBuildingBinding::isCropsEdible },
        { "eat", FarmBuildingBinding::eat },
        { "getYieldChancePerCrop", FarmBuildingBinding::getYieldChancePerCrop },
        { "getCropMult", FarmBuildingBinding::getCropMult },
        { "serialise", FarmBuildingBinding::serialise },
        { "_NV_serialise", FarmBuildingBinding::_NV_serialise },
        { "loadFromSerialise", FarmBuildingBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", FarmBuildingBinding::_NV_loadFromSerialise },
        { "getDirectionMarker", FarmBuildingBinding::getDirectionMarker },
        { "_NV_getDirectionMarker", FarmBuildingBinding::_NV_getDirectionMarker },
        { "dontNeedWorkRightNow", FarmBuildingBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", FarmBuildingBinding::_NV_dontNeedWorkRightNow },
        { "getFertilityMultiplier", FarmBuildingBinding::getFertilityMultiplier },
        { "setupMaterial", FarmBuildingBinding::setupMaterial },
        { "updateMaterial", FarmBuildingBinding::updateMaterial },
        { "updatePlantInstance", FarmBuildingBinding::updatePlantInstance },
        { "createPlants", FarmBuildingBinding::createPlants },
        { "createClickHull", FarmBuildingBinding::createClickHull },
        { "createEntity", FarmBuildingBinding::createEntity },
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

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
