#include "pch.h"
#include "kenshi/Weather.h"
#include "kenshi/PhysicsCollection.h"
#include "WeatherSystemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/ListenerBinding.h"
#include "Bindings/Kenshi/RotatingEntBinding.h"
#include "Bindings/Kenshi/WeatherRegionBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystem_FogValuesBinding.h"
#include "Bindings/Kenshi/Weather/WeatherSystem_ZoneFogBinding.h"

namespace KenshiLua
{

// getInstance allocates 0x288 bytes for the singleton.
static_assert(sizeof(WeatherSystem) == 0x288, "WeatherSystem size does not match the game");
static_assert(offsetof(WeatherSystem, areaFog) == 0x50, "WeatherSystem::areaFog offset does not match the game");
static_assert(offsetof(WeatherSystem, currentZoneFog) == 0x1B8, "WeatherSystem::currentZoneFog offset does not match the game");
static_assert(offsetof(WeatherSystem, weatherListeners) == 0x238, "WeatherSystem::weatherListeners offset does not match the game");

static WeatherSystem* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherSystem>(L, idx, WeatherSystemBinding::getMetatableName());
}

// --- Static Methods ---
int WeatherSystemBinding::getInstanceMethod(lua_State* L)
{
    return pushObject<WeatherSystem>(L, WeatherSystem::getInstance(), WeatherSystemBinding::getMetatableName());
}

// --- Getters for WeatherSystem ---
static int WeatherSystem_get_ActiveRegionWeather(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushObject<WeatherRegion>(L, instance->ActiveRegionWeather, WeatherRegionBinding::getMetatableName());
}

static int WeatherSystem_get_exitingBiome(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushboolean(L, instance->exitingBiome ? 1 : 0);
    return 1;
}

static int WeatherSystem_get_previousBiomeAABB(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    pushVector4(L, instance->previousBiomeAABB);
    return 1;
}

// The elements are borrowed and can be edited in place; the array itself is not assignable.
static int WeatherSystem_get_areaFog(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    const int count = (int)(sizeof(instance->areaFog) / sizeof(instance->areaFog[0]));
    lua_createtable(L, count, 0);
    for (int i = 0; i < count; ++i)
    {
        pushObject<WeatherSystem::ZoneFog>(L, &instance->areaFog[i], WeatherSystem_ZoneFogBinding::getMetatableName());
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

static int WeatherSystem_get_previousPoint(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    pushVector3(L, instance->previousPoint);
    return 1;
}

static int WeatherSystem_get_zoneFogBlendingPosition(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    pushVector3(L, instance->zoneFogBlendingPosition);
    return 1;
}

static int WeatherSystem_get_zoneFogBlendingType(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushinteger(L, instance->zoneFogBlendingType);
    return 1;
}

static int WeatherSystem_get_previousZoneFog(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushObject<WeatherSystem::ZoneFog>(L, &instance->previousZoneFog, WeatherSystem_ZoneFogBinding::getMetatableName());
}

static int WeatherSystem_get_currentZoneFog(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushObject<WeatherSystem::ZoneFog>(L, &instance->currentZoneFog, WeatherSystem_ZoneFogBinding::getMetatableName());
}

static int WeatherSystem_get_currentFogValues(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushObject<WeatherSystem::FogValues>(L, &instance->currentFogValues, WeatherSystem_FogValuesBinding::getMetatableName());
}

static int WeatherSystem_get_currentWindValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushnumber(L, instance->currentWindValue);
    return 1;
}

static int WeatherSystem_get_currentRainValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushnumber(L, instance->currentRainValue);
    return 1;
}

static int WeatherSystem_get_rainValueUpdated(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushboolean(L, instance->rainValueUpdated ? 1 : 0);
    return 1;
}

static int WeatherSystem_get_globalWetness(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushnumber(L, instance->globalWetness);
    return 1;
}

static int WeatherSystem_get_currentDustAmount(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    pushVector3(L, instance->currentDustAmount);
    return 1;
}

static int WeatherSystem_get_heatHazeUpdated(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushboolean(L, instance->heatHazeUpdated ? 1 : 0);
    return 1;
}

static int WeatherSystem_get_heatHazeValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    lua_pushnumber(L, instance->heatHazeValue);
    return 1;
}

// --- Setters for WeatherSystem ---
// updateMT returns early while no region is active.
static int WeatherSystem_set_ActiveRegionWeather(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->ActiveRegionWeather = lua_isnoneornil(L, 2) ? nullptr : checkObject<WeatherRegion>(L, 2, WeatherRegionBinding::getMetatableName());
    return 0;
}

static int WeatherSystem_set_exitingBiome(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->exitingBiome = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherSystem_set_previousBiomeAABB(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!readVector4(L, 2, instance->previousBiomeAABB)) return luaL_argerror(L, 2, "Vector4 table expected");
    return 0;
}

static int WeatherSystem_set_previousPoint(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!readVector3(L, 2, instance->previousPoint)) return luaL_argerror(L, 2, "Vector3 table expected");
    return 0;
}

static int WeatherSystem_set_zoneFogBlendingPosition(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!readVector3(L, 2, instance->zoneFogBlendingPosition)) return luaL_argerror(L, 2, "Vector3 table expected");
    return 0;
}

static int WeatherSystem_set_zoneFogBlendingType(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->zoneFogBlendingType = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

static int WeatherSystem_set_previousZoneFog(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->previousZoneFog = *checkObject<WeatherSystem::ZoneFog>(L, 2, WeatherSystem_ZoneFogBinding::getMetatableName());
    return 0;
}

static int WeatherSystem_set_currentZoneFog(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->currentZoneFog = *checkObject<WeatherSystem::ZoneFog>(L, 2, WeatherSystem_ZoneFogBinding::getMetatableName());
    return 0;
}

static int WeatherSystem_set_currentFogValues(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->currentFogValues = *checkObject<WeatherSystem::FogValues>(L, 2, WeatherSystem_FogValuesBinding::getMetatableName());
    return 0;
}

static int WeatherSystem_set_currentWindValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->currentWindValue = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherSystem_set_currentRainValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->currentRainValue = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherSystem_set_rainValueUpdated(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->rainValueUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherSystem_set_globalWetness(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->globalWetness = (float)luaL_checknumber(L, 2);
    return 0;
}

static int WeatherSystem_set_currentDustAmount(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!readVector3(L, 2, instance->currentDustAmount)) return luaL_argerror(L, 2, "Vector3 table expected");
    return 0;
}

static int WeatherSystem_set_heatHazeUpdated(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->heatHazeUpdated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int WeatherSystem_set_heatHazeValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->heatHazeValue = (float)luaL_checknumber(L, 2);
    return 0;
}

int WeatherSystemBinding::reset(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    instance->reset();
    return 0;
}

int WeatherSystemBinding::updateMT(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    instance->updateMT();
    return 0;
}

int WeatherSystemBinding::updateBT(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    instance->updateBT();
    return 0;
}

int WeatherSystemBinding::updateUT(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    instance->updateUT();
    return 0;
}

int WeatherSystemBinding::addWeatherListener(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    // RotatingEnt holds its Listener base at offset 0x38, so its pointer is converted, not reinterpreted.
    WeatherRegion::Listener* listener = testObject<WeatherRegion::Listener>(L, 3, ListenerBinding::getMetatableName());
    if (!listener)
        listener = static_cast<WeatherRegion::Listener*>(checkObject<PhysicsCollection::RotatingEnt>(L, 3, RotatingEntBinding::getMetatableName()));

    // addWeatherListener(Vector3 position, Listener) or addWeatherListener(GameData biome, Listener)
    if (lua_istable(L, 2))
    {
        Ogre::Vector3 position;
        readVector3(L, 2, position);
        instance->addWeatherListener(position, listener);
        return 0;
    }
    GameData* biome = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->addWeatherListener(biome, listener);
    return 0;
}

int WeatherSystemBinding::removeWeatherListener(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    // RotatingEnt holds its Listener base at offset 0x38, so its pointer is converted, not reinterpreted.
    WeatherRegion::Listener* listener = testObject<WeatherRegion::Listener>(L, 2, ListenerBinding::getMetatableName());
    if (!listener)
        listener = static_cast<WeatherRegion::Listener*>(checkObject<PhysicsCollection::RotatingEnt>(L, 2, RotatingEntBinding::getMetatableName()));
    instance->removeWeatherListener(listener);
    return 0;
}

int WeatherSystemBinding::setDustShaderValue(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");

    Ogre::Vector3 value;
    if (!readVector3(L, 2, value)) return luaL_argerror(L, 2, "Vector3 table expected");
    instance->setDustShaderValue(value);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 199: ~WeatherSystem() - destructor; the game owns the singleton
  line 202: destroy() - deletes the singleton while the game keeps using it through getInstance's static pointer
  line 210: getPositionGlobalEffects(...) - returns a std::vector<std::pair<EffectType::Enum, float> > with no container binding, and reads the biome at the position without a null check
  line 211: addWeatherEffect(EffectHandler* effect) - EffectHandler is unbound
  line 212: removeWeatherEffect(EffectHandler* effect) - EffectHandler is unbound
  line 217: WeatherSystem() - constructor; getInstance creates the singleton

Skipped properties needing manual binding:
  line 215: ActiveRegion (AreaBiomeGroup*) - unbound pointer
  line 245: previousArea (AreaBiomeGroup*) - unbound pointer
  line 246: areaGroups (AreaBiomeGroup*[4]) - unbound pointer
  line 248: previousSector (AreaSector*) - unbound pointer
  line 262: weatherListeners (std::map<WeatherRegion::Listener*, WeatherRegion*, ...>) - no container binding for this map
  line 263: activeEffects (std::set<EffectHandler*, ...>) - EffectHandler is unbound
*/

int WeatherSystemBinding::gc(lua_State* L)
{
    // Borrowed: the game owns the singleton
    return 0;
}

int WeatherSystemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.WeatherSystem object");
    return 1;
}

void WeatherSystemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WeatherSystemBinding::gc },
        { "__tostring", WeatherSystemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getInstance", WeatherSystemBinding::getInstanceMethod },
        { "reset", WeatherSystemBinding::reset },
        { "updateMT", WeatherSystemBinding::updateMT },
        { "updateBT", WeatherSystemBinding::updateBT },
        { "updateUT", WeatherSystemBinding::updateUT },
        { "addWeatherListener", WeatherSystemBinding::addWeatherListener },
        { "removeWeatherListener", WeatherSystemBinding::removeWeatherListener },
        { "setDustShaderValue", WeatherSystemBinding::setDustShaderValue },
        { 0, 0 }
    };

    registerClass(
        L,
        WeatherSystemBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, WeatherSystemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "ActiveRegionWeather", WeatherSystem_get_ActiveRegionWeather);
    registerGetter(L, "exitingBiome", WeatherSystem_get_exitingBiome);
    registerGetter(L, "previousBiomeAABB", WeatherSystem_get_previousBiomeAABB);
    registerGetter(L, "areaFog", WeatherSystem_get_areaFog);
    registerGetter(L, "previousPoint", WeatherSystem_get_previousPoint);
    registerGetter(L, "zoneFogBlendingPosition", WeatherSystem_get_zoneFogBlendingPosition);
    registerGetter(L, "zoneFogBlendingType", WeatherSystem_get_zoneFogBlendingType);
    registerGetter(L, "previousZoneFog", WeatherSystem_get_previousZoneFog);
    registerGetter(L, "currentZoneFog", WeatherSystem_get_currentZoneFog);
    registerGetter(L, "currentFogValues", WeatherSystem_get_currentFogValues);
    registerGetter(L, "currentWindValue", WeatherSystem_get_currentWindValue);
    registerGetter(L, "currentRainValue", WeatherSystem_get_currentRainValue);
    registerGetter(L, "rainValueUpdated", WeatherSystem_get_rainValueUpdated);
    registerGetter(L, "globalWetness", WeatherSystem_get_globalWetness);
    registerGetter(L, "currentDustAmount", WeatherSystem_get_currentDustAmount);
    registerGetter(L, "heatHazeUpdated", WeatherSystem_get_heatHazeUpdated);
    registerGetter(L, "heatHazeValue", WeatherSystem_get_heatHazeValue);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "ActiveRegionWeather", WeatherSystem_set_ActiveRegionWeather);
    registerSetter(L, "exitingBiome", WeatherSystem_set_exitingBiome);
    registerSetter(L, "previousBiomeAABB", WeatherSystem_set_previousBiomeAABB);
    registerSetter(L, "previousPoint", WeatherSystem_set_previousPoint);
    registerSetter(L, "zoneFogBlendingPosition", WeatherSystem_set_zoneFogBlendingPosition);
    registerSetter(L, "zoneFogBlendingType", WeatherSystem_set_zoneFogBlendingType);
    registerSetter(L, "previousZoneFog", WeatherSystem_set_previousZoneFog);
    registerSetter(L, "currentZoneFog", WeatherSystem_set_currentZoneFog);
    registerSetter(L, "currentFogValues", WeatherSystem_set_currentFogValues);
    registerSetter(L, "currentWindValue", WeatherSystem_set_currentWindValue);
    registerSetter(L, "currentRainValue", WeatherSystem_set_currentRainValue);
    registerSetter(L, "rainValueUpdated", WeatherSystem_set_rainValueUpdated);
    registerSetter(L, "globalWetness", WeatherSystem_set_globalWetness);
    registerSetter(L, "currentDustAmount", WeatherSystem_set_currentDustAmount);
    registerSetter(L, "heatHazeUpdated", WeatherSystem_set_heatHazeUpdated);
    registerSetter(L, "heatHazeValue", WeatherSystem_set_heatHazeValue);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "WeatherSystem");
    registerStaticMethod(L, "getInstance", WeatherSystemBinding::getInstanceMethod);
    lua_setglobal(L, "WeatherSystem");
}

} // namespace KenshiLua
