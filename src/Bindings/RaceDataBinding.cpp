#include "pch.h"
#include "kenshi\RaceData.h"
#include "RaceDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/EnumBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static RaceData* getInstance(lua_State* L, int idx)
{
    return checkObject<RaceData>(L, idx, RaceDataBinding::getMetatableName());
}

// --- Getters for RaceData ---
static int RaceData_get_data(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    return pushObject<GameData>(L, instance->data, GameDataBinding::getMetatableName());
}

static int RaceData_get_runSpeedMaxSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->runSpeedMaxSkill);
    return 1;
}

static int RaceData_get_runSpeedMinSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->runSpeedMinSkill);
    return 1;
}

static int RaceData_get_originalBloodMin(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->originalBloodMin);
    return 1;
}

static int RaceData_get_originalBloodMax(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->originalBloodMax);
    return 1;
}

static int RaceData_get_healRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->healRate);
    return 1;
}

static int RaceData_get_bleedRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->bleedRate);
    return 1;
}

static int RaceData_get_swimSpeed(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->swimSpeed);
    return 1;
}

static int RaceData_get_walkSpeed(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->walkSpeed);
    return 1;
}

static int RaceData_get_swimOffset(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->swimOffset);
    return 1;
}

static int RaceData_get_waterAvoidance(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->waterAvoidance);
    return 1;
}

static int RaceData_get_hungerRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->hungerRate);
    return 1;
}

static int RaceData_get_visionMultiplier(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushnumber(L, instance->visionMultiplier);
    return 1;
}

static int RaceData_get_gigantic(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->gigantic ? 1 : 0);
    return 1;
}

static int RaceData_get_swims(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->swims ? 1 : 0);
    return 1;
}

static int RaceData_get_carriable(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->carriable ? 1 : 0);
    return 1;
}

static int RaceData_get_singleGender(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->singleGender ? 1 : 0);
    return 1;
}

static int RaceData_get_robot(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->robot ? 1 : 0);
    return 1;
}

static int RaceData_get_vampiric(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->vampiric ? 1 : 0);
    return 1;
}

static int RaceData_get_noHats(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->noHats ? 1 : 0);
    return 1;
}

static int RaceData_get_noShirts(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->noShirts ? 1 : 0);
    return 1;
}

static int RaceData_get_noShoes(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->noShoes ? 1 : 0);
    return 1;
}

static int RaceData_get_extraAttackSlots(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushinteger(L, instance->extraAttackSlots);
    return 1;
}

static int RaceData_get_firstAidSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushinteger(L, (lua_Integer)instance->firstAidSkill);
    return 1;
}

static int RaceData_get_canGoIndoors(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushboolean(L, instance->canGoIndoors ? 1 : 0);
    return 1;
}

static int RaceData_get_raceGroup(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    lua_pushlightuserdata(L, (void*)instance->raceGroup);
    return 1;
}

// --- Setters for RaceData ---
static int RaceData_set_data(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->data = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int RaceData_set_runSpeedMaxSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->runSpeedMaxSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_runSpeedMinSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->runSpeedMinSkill = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_originalBloodMin(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->originalBloodMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_originalBloodMax(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->originalBloodMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_healRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->healRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_bleedRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->bleedRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_swimSpeed(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->swimSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_walkSpeed(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->walkSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_swimOffset(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->swimOffset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_waterAvoidance(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->waterAvoidance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_hungerRate(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->hungerRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_visionMultiplier(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->visionMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RaceData_set_gigantic(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->gigantic = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_swims(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->swims = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_carriable(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->carriable = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_singleGender(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->singleGender = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_robot(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->robot = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_vampiric(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->vampiric = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noHats(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->noHats = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noShirts(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->noShirts = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_noShoes(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->noShoes = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RaceData_set_extraAttackSlots(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->extraAttackSlots = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int RaceData_set_firstAidSkill(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->firstAidSkill = (StatsEnumerated)luaL_checkinteger(L, 2);
    return 0;
}

static int RaceData_set_canGoIndoors(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->canGoIndoors = lua_toboolean(L, 2) != 0;
    return 0;
}

int RaceDataBinding::isSpecificRace(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");

    GameData* subrace = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool result = instance->isSpecificRace(subrace);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RaceDataBinding::getStatMod(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");

    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = instance->getStatMod(stat);
    lua_pushnumber(L, result);
    return 1;
}

int RaceDataBinding::isImmune(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");

    WeatherAffecting w = (WeatherAffecting)luaL_checkinteger(L, 2);
    bool result = instance->isImmune(w);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RaceDataBinding::getRaceData(lua_State* L)
{
    if (lua_isstring(L, 1))
    {
        std::string stringID = luaL_checkstring(L, 1);
        RaceData* result = RaceData::getRaceData(stringID);
        return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
    }
    else
    {
        GameData* data = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
        RaceData* result = RaceData::getRaceData(data);
        return pushObject<RaceData>(L, result, RaceDataBinding::getMetatableName());
    }
}

int RaceDataBinding::isRelatedRace(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");

    if (testObject<RaceData>(L, 2, RaceDataBinding::getMetatableName()) != nullptr)
    {
        RaceData* data = checkObject<RaceData>(L, 2, RaceDataBinding::getMetatableName());
        bool result = instance->isRelatedRace(data);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        bool result = instance->isRelatedRace(d);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

int RaceDataBinding::canEat(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");

    bool isAnimal = lua_toboolean(L, 3) != 0;
    if (testObject<Item>(L, 2, ItemBinding::getMetatableName()) != nullptr)
    {
        Item* food = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
        bool result = instance->canEat(food, isAnimal);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        GameData* food = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        bool result = instance->canEat(food, isAnimal);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - RaceData_get_raceGroup: RaceGroupData* (unbound pointer)
*/

int RaceDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RaceDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RaceData object");
    return 1;
}



static int RaceData_get_bloodColour(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    pushColourValue(L, instance->bloodColour);
    return 1;
}

static int RaceData_get_specialFoods(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    return pushObject<ogre_unordered_set<GameData*>::type>(L, &instance->specialFoods, OgreUnorderedSetBinding<GameData*>::getMetatableName());
}

static int RaceData_get_statMods(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    return pushObject<ogre_unordered_map<StatsEnumerated, float>::type>(L, &instance->statMods, OgreUnorderedMapBinding<StatsEnumerated, float>::getMetatableName());
}

static int RaceData_get_weatherImmunities(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    return pushObject<ogre_unordered_set<WeatherAffecting>::type>(L, &instance->weatherImmunities, OgreUnorderedSetBinding<WeatherAffecting>::getMetatableName());
}

static int RaceData_set_bloodColour(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    if (!readColourValue(L, 2, instance->bloodColour)) {
        return luaL_error(L, "Argument 2 to set 'bloodColour' must be a table {r, g, b, a}");
    }
    return 0;
}


static int RaceData_set_raceGroup(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    instance->raceGroup = (RaceGroupData*)lua_touserdata(L, 2);
    return 0;
}


static int RaceData_set_specialFoods(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    auto* val = OgreUnorderedSetBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'specialFoods' must be ogre_unordered_set<GameData*>");
    instance->specialFoods = *val;
    return 0;
}


static int RaceData_set_statMods(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    auto* val = OgreUnorderedMapBinding<StatsEnumerated, float>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'statMods' must be ogre_unordered_map<StatsEnumerated, float>");
    instance->statMods = *val;
    return 0;
}


static int RaceData_set_weatherImmunities(lua_State* L)
{
    RaceData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RaceData is nil");
    auto* val = OgreUnorderedSetBinding<WeatherAffecting>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'weatherImmunities' must be ogre_unordered_set<WeatherAffecting>");
    instance->weatherImmunities = *val;
    return 0;
}


void RaceDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RaceDataBinding::gc },
        { "__tostring", RaceDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getRaceData", RaceDataBinding::getRaceData },
        { "isRelatedRace", RaceDataBinding::isRelatedRace },
        { "isSpecificRace", RaceDataBinding::isSpecificRace },
        { "getStatMod", RaceDataBinding::getStatMod },
        { "isImmune", RaceDataBinding::isImmune },
        { "canEat", RaceDataBinding::canEat },
        { 0, 0 }
    };

    registerClass(
        L, 
        RaceDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RaceDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "data", RaceData_get_data);
    registerGetter(L, "runSpeedMaxSkill", RaceData_get_runSpeedMaxSkill);
    registerGetter(L, "runSpeedMinSkill", RaceData_get_runSpeedMinSkill);
    registerGetter(L, "originalBloodMin", RaceData_get_originalBloodMin);
    registerGetter(L, "originalBloodMax", RaceData_get_originalBloodMax);
    registerGetter(L, "healRate", RaceData_get_healRate);
    registerGetter(L, "bleedRate", RaceData_get_bleedRate);
    registerGetter(L, "swimSpeed", RaceData_get_swimSpeed);
    registerGetter(L, "walkSpeed", RaceData_get_walkSpeed);
    registerGetter(L, "swimOffset", RaceData_get_swimOffset);
    registerGetter(L, "waterAvoidance", RaceData_get_waterAvoidance);
    registerGetter(L, "hungerRate", RaceData_get_hungerRate);
    registerGetter(L, "visionMultiplier", RaceData_get_visionMultiplier);
    registerGetter(L, "gigantic", RaceData_get_gigantic);
    registerGetter(L, "swims", RaceData_get_swims);
    registerGetter(L, "carriable", RaceData_get_carriable);
    registerGetter(L, "singleGender", RaceData_get_singleGender);
    registerGetter(L, "robot", RaceData_get_robot);
    registerGetter(L, "vampiric", RaceData_get_vampiric);
    registerGetter(L, "noHats", RaceData_get_noHats);
    registerGetter(L, "noShirts", RaceData_get_noShirts);
    registerGetter(L, "noShoes", RaceData_get_noShoes);
    registerGetter(L, "extraAttackSlots", RaceData_get_extraAttackSlots);
    registerGetter(L, "firstAidSkill", RaceData_get_firstAidSkill);
    registerGetter(L, "canGoIndoors", RaceData_get_canGoIndoors);
    registerGetter(L, "raceGroup", RaceData_get_raceGroup);
    registerGetter(L, "bloodColour", RaceData_get_bloodColour);
    registerGetter(L, "specialFoods", RaceData_get_specialFoods);
    registerGetter(L, "statMods", RaceData_get_statMods);
    registerGetter(L, "weatherImmunities", RaceData_get_weatherImmunities);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "data", RaceData_set_data);
    registerSetter(L, "runSpeedMaxSkill", RaceData_set_runSpeedMaxSkill);
    registerSetter(L, "runSpeedMinSkill", RaceData_set_runSpeedMinSkill);
    registerSetter(L, "originalBloodMin", RaceData_set_originalBloodMin);
    registerSetter(L, "originalBloodMax", RaceData_set_originalBloodMax);
    registerSetter(L, "healRate", RaceData_set_healRate);
    registerSetter(L, "bleedRate", RaceData_set_bleedRate);
    registerSetter(L, "swimSpeed", RaceData_set_swimSpeed);
    registerSetter(L, "walkSpeed", RaceData_set_walkSpeed);
    registerSetter(L, "swimOffset", RaceData_set_swimOffset);
    registerSetter(L, "waterAvoidance", RaceData_set_waterAvoidance);
    registerSetter(L, "hungerRate", RaceData_set_hungerRate);
    registerSetter(L, "visionMultiplier", RaceData_set_visionMultiplier);
    registerSetter(L, "gigantic", RaceData_set_gigantic);
    registerSetter(L, "swims", RaceData_set_swims);
    registerSetter(L, "carriable", RaceData_set_carriable);
    registerSetter(L, "singleGender", RaceData_set_singleGender);
    registerSetter(L, "robot", RaceData_set_robot);
    registerSetter(L, "vampiric", RaceData_set_vampiric);
    registerSetter(L, "noHats", RaceData_set_noHats);
    registerSetter(L, "noShirts", RaceData_set_noShirts);
    registerSetter(L, "noShoes", RaceData_set_noShoes);
    registerSetter(L, "extraAttackSlots", RaceData_set_extraAttackSlots);
    registerSetter(L, "firstAidSkill", RaceData_set_firstAidSkill);
    registerSetter(L, "canGoIndoors", RaceData_set_canGoIndoors);
    registerSetter(L, "bloodColour", RaceData_set_bloodColour);
    registerSetter(L, "raceGroup", RaceData_set_raceGroup);
    registerSetter(L, "specialFoods", RaceData_set_specialFoods);
    registerSetter(L, "statMods", RaceData_set_statMods);
    registerSetter(L, "weatherImmunities", RaceData_set_weatherImmunities);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    OgreUnorderedMapBinding<StatsEnumerated, float>::registerBinding(L, "ogre_unordered_map<StatsEnumerated, float>", nullptr, nullptr);
    OgreUnorderedSetBinding<WeatherAffecting>::registerBinding(L, "ogre_unordered_set<WeatherAffecting>", nullptr);

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua