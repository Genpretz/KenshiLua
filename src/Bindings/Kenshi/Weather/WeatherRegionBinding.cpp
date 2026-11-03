#include "pch.h"
#include "kenshi/Weather.h"
#include "kenshi/PhysicsCollection.h"
#include "WeatherRegionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/ListenerBinding.h"
#include "Bindings/Kenshi/RotatingEntBinding.h"
#include "Bindings/Kenshi/Weather/SeasonBinding.h"
#include "Bindings/Kenshi/Weather/WeatherInstanceBinding.h"

namespace KenshiLua
{

static WeatherRegion* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherRegion>(L, idx, WeatherRegionBinding::getMetatableName());
}

// --- Getters for WeatherRegion ---
static int WeatherRegion_get_biomeGroup(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushlightuserdata(L, (void*)instance->biomeGroup);
    return 1;
}

static int WeatherRegion_get_weatherStrengthMultiplierMin(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushnumber(L, instance->weatherStrengthMultiplierMin);
    return 1;
}

static int WeatherRegion_get_weatherStrengthMultiplierMax(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushnumber(L, instance->weatherStrengthMultiplierMax);
    return 1;
}

static int WeatherRegion_get_weatherInstance(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    return pushObject<WeatherInstance>(L, instance->weatherInstance, WeatherInstanceBinding::getMetatableName());
}

static int WeatherRegion_get_currentSeason(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    return pushObject<Season>(L, instance->currentSeason, SeasonBinding::getMetatableName());
}

// ~WeatherRegion deletes these seasons, so the list is returned as a table and cannot be edited.
static int WeatherRegion_get_seasons(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_createtable(L, (int)instance->seasons.size(), 0);
    for (size_t i = 0; i < instance->seasons.size(); ++i)
    {
        pushObject<Season>(L, instance->seasons[i], SeasonBinding::getMetatableName());
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

static int WeatherRegion_get_currentSeasonIndex(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushinteger(L, instance->currentSeasonIndex);
    return 1;
}

static int WeatherRegion_get_currentSeasonEndDay(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushinteger(L, instance->currentSeasonEndDay);
    return 1;
}

static int WeatherRegion_get_biomeGroupLoaded(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushboolean(L, instance->biomeGroupLoaded ? 1 : 0);
    return 1;
}

static int WeatherRegion_get_requestUpdateEffects(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushboolean(L, instance->requestUpdateEffects ? 1 : 0);
    return 1;
}

static int WeatherRegion_get_activeCameraBiome(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushboolean(L, instance->activeCameraBiome ? 1 : 0);
    return 1;
}

static int WeatherRegion_get_weatherUpdated(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushboolean(L, instance->weatherUpdated ? 1 : 0);
    return 1;
}

static int WeatherRegion_get_instanceUpdated(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    lua_pushboolean(L, instance->instanceUpdated ? 1 : 0);
    return 1;
}

// --- Setters for WeatherRegion ---
static int WeatherRegion_set_weatherStrengthMultiplierMin(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->weatherStrengthMultiplierMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherRegion_set_weatherStrengthMultiplierMax(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->weatherStrengthMultiplierMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherRegion_set_currentSeasonIndex(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->currentSeasonIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherRegion_set_currentSeasonEndDay(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->currentSeasonEndDay = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherRegion_set_biomeGroupLoaded(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->biomeGroupLoaded = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherRegion_set_requestUpdateEffects(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->requestUpdateEffects = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherRegion_set_activeCameraBiome(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->activeCameraBiome = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherRegion_set_weatherUpdated(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->weatherUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherRegion_set_instanceUpdated(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");
    instance->instanceUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

int WeatherRegionBinding::reset(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    instance->reset();
    return 0;
}

int WeatherRegionBinding::getWeatherInstance(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    WeatherInstance* result = instance->getWeatherInstance();
    return pushObject<WeatherInstance>(L, result, WeatherInstanceBinding::getMetatableName());
}

int WeatherRegionBinding::setCurrentSeason(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    int seasonIndex = (int)luaL_checkinteger(L, 2);
    int seasonEnd = (int)luaL_checkinteger(L, 3);
    instance->setCurrentSeason(seasonIndex, seasonEnd);
    return 0;
}

int WeatherRegionBinding::getNewWeatherStrength(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    float result = instance->getNewWeatherStrength();
    lua_pushnumber(L, result);
    return 1;
}

int WeatherRegionBinding::update(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    instance->update();
    return 0;
}

int WeatherRegionBinding::updateBT(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    instance->updateBT();
    return 0;
}

int WeatherRegionBinding::addListener(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    // RotatingEnt holds its Listener base at offset 0x38, so its pointer is converted, not reinterpreted.
    // weatherChanged calls every listener without a null check.
    WeatherRegion::Listener* listener = testObject<WeatherRegion::Listener>(L, 2, ListenerBinding::getMetatableName());
    if (!listener)
        listener = static_cast<WeatherRegion::Listener*>(checkObject<PhysicsCollection::RotatingEnt>(L, 2, RotatingEntBinding::getMetatableName()));
    instance->addListener(listener);
    return 0;
}

int WeatherRegionBinding::removeListener(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    // RotatingEnt holds its Listener base at offset 0x38, so its pointer is converted, not reinterpreted.
    WeatherRegion::Listener* listener = testObject<WeatherRegion::Listener>(L, 2, ListenerBinding::getMetatableName());
    if (!listener)
        listener = static_cast<WeatherRegion::Listener*>(checkObject<PhysicsCollection::RotatingEnt>(L, 2, RotatingEntBinding::getMetatableName()));
    instance->removeListener(listener);
    return 0;
}

int WeatherRegionBinding::addGlobalEffect(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    EffectType::Enum type = (EffectType::Enum)luaL_checkinteger(L, 2);
    instance->addGlobalEffect(type);
    return 0;
}

int WeatherRegionBinding::getNewSeason(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    instance->getNewSeason();
    return 0;
}

int WeatherRegionBinding::weatherChanged(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    bool newWeather = lua_toboolean(L, 2) != 0;
    instance->weatherChanged(newWeather);
    return 0;
}

int WeatherRegionBinding::updateWeatherEffects(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    instance->updateWeatherEffects();
    return 0;
}

int WeatherRegionBinding::save(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string key = luaL_checkstring(L, 3);
    instance->save(data, key);
    return 0;
}

int WeatherRegionBinding::load(lua_State* L)
{
    WeatherRegion* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherRegion is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    const std::string key = luaL_checkstring(L, 3);
    instance->load(data, key);
    return 0;
}


/*
LIGHTUSERDATA DEPENDENCIES:
  - WeatherRegion_get_biomeGroup: AreaBiomeGroup* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 109: listeners (Ogre::vector<WeatherRegion::Listener*>::type) - unsupported type
  line 112: effects (Ogre::vector<EffectGroup*>::type) - unsupported type
  line 113: activeGlobalEffects (std::vector<std::pair<EffectType::Enum, float>, Ogre::STLAllocator<std::pair<EffectType::Enum, float>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int WeatherRegionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int WeatherRegionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WeatherRegion object");
    return 1;
}

void WeatherRegionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherRegionBinding::gc },
        { "__tostring", WeatherRegionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "reset", WeatherRegionBinding::reset },
        { "getWeatherInstance", WeatherRegionBinding::getWeatherInstance },
        { "setCurrentSeason", WeatherRegionBinding::setCurrentSeason },
        { "getNewWeatherStrength", WeatherRegionBinding::getNewWeatherStrength },
        { "update", WeatherRegionBinding::update },
        { "updateBT", WeatherRegionBinding::updateBT },
        { "addListener", WeatherRegionBinding::addListener },
        { "removeListener", WeatherRegionBinding::removeListener },
        { "addGlobalEffect", WeatherRegionBinding::addGlobalEffect },
        { "getNewSeason", WeatherRegionBinding::getNewSeason },
        { "weatherChanged", WeatherRegionBinding::weatherChanged },
        { "updateWeatherEffects", WeatherRegionBinding::updateWeatherEffects },
        { "save", WeatherRegionBinding::save },
        { "load", WeatherRegionBinding::load },
        { 0, 0 }
    };

    registerClass(
        L, 
        WeatherRegionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherRegionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "biomeGroup", WeatherRegion_get_biomeGroup);
    registerGetter(L, "weatherStrengthMultiplierMin", WeatherRegion_get_weatherStrengthMultiplierMin);
    registerGetter(L, "weatherStrengthMultiplierMax", WeatherRegion_get_weatherStrengthMultiplierMax);
    registerGetter(L, "weatherInstance", WeatherRegion_get_weatherInstance);
    registerGetter(L, "seasons", WeatherRegion_get_seasons);
    registerGetter(L, "currentSeason", WeatherRegion_get_currentSeason);
    registerGetter(L, "currentSeasonIndex", WeatherRegion_get_currentSeasonIndex);
    registerGetter(L, "currentSeasonEndDay", WeatherRegion_get_currentSeasonEndDay);
    registerGetter(L, "biomeGroupLoaded", WeatherRegion_get_biomeGroupLoaded);
    registerGetter(L, "requestUpdateEffects", WeatherRegion_get_requestUpdateEffects);
    registerGetter(L, "activeCameraBiome", WeatherRegion_get_activeCameraBiome);
    registerGetter(L, "weatherUpdated", WeatherRegion_get_weatherUpdated);
    registerGetter(L, "instanceUpdated", WeatherRegion_get_instanceUpdated);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "weatherStrengthMultiplierMin", WeatherRegion_set_weatherStrengthMultiplierMin);
    registerSetter(L, "weatherStrengthMultiplierMax", WeatherRegion_set_weatherStrengthMultiplierMax);
    registerSetter(L, "currentSeasonIndex", WeatherRegion_set_currentSeasonIndex);
    registerSetter(L, "currentSeasonEndDay", WeatherRegion_set_currentSeasonEndDay);
    registerSetter(L, "biomeGroupLoaded", WeatherRegion_set_biomeGroupLoaded);
    registerSetter(L, "requestUpdateEffects", WeatherRegion_set_requestUpdateEffects);
    registerSetter(L, "activeCameraBiome", WeatherRegion_set_activeCameraBiome);
    registerSetter(L, "weatherUpdated", WeatherRegion_set_weatherUpdated);
    registerSetter(L, "instanceUpdated", WeatherRegion_set_instanceUpdated);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, WeatherRegionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua