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

#include <map>
#include <set>
#include <vector>

namespace KenshiLua
{

// getInstance allocates 0x288 bytes for the singleton.
static_assert(sizeof(WeatherSystem) == 0x288, "WeatherSystem size does not match the game");
static_assert(offsetof(WeatherSystem, areaFog) == 0x50, "WeatherSystem::areaFog offset does not match the game");
static_assert(offsetof(WeatherSystem, currentZoneFog) == 0x1B8, "WeatherSystem::currentZoneFog offset does not match the game");
static_assert(offsetof(WeatherSystem, weatherListeners) == 0x238, "WeatherSystem::weatherListeners offset does not match the game");
static_assert(offsetof(WeatherSystem, activeEffects) == 0x260, "WeatherSystem::activeEffects offset does not match the game");

typedef std::vector<std::pair<EffectType::Enum, float>, Ogre::STLAllocator<std::pair<EffectType::Enum, float>, Ogre::GeneralAllocPolicy> > GlobalEffectList;
typedef std::map<WeatherRegion::Listener*, WeatherRegion*, std::less<WeatherRegion::Listener*>, Ogre::STLAllocator<std::pair<WeatherRegion::Listener* const, WeatherRegion*>, Ogre::GeneralAllocPolicy> > WeatherListenerMap;
typedef std::set<EffectHandler*, std::less<EffectHandler*>, Ogre::STLAllocator<EffectHandler*, Ogre::GeneralAllocPolicy> > WeatherEffectSet;

static WeatherSystem* getInstance(lua_State* L, int idx)
{
    return checkObject<WeatherSystem>(L, idx, WeatherSystemBinding::getMetatableName());
}

static int pushOpaquePointer(lua_State* L, const void* value)
{
    if (value)
        lua_pushlightuserdata(L, const_cast<void*>(value));
    else
        lua_pushnil(L);
    return 1;
}

template <typename T>
static T* checkOpaquePointer(lua_State* L, int idx, const char* expected, bool allowNil)
{
    if (lua_isnoneornil(L, idx))
    {
        if (allowNil) return nullptr;
        luaL_argerror(L, idx, expected);
        return nullptr;
    }
    if (!lua_islightuserdata(L, idx))
    {
        luaL_argerror(L, idx, expected);
        return nullptr;
    }
    return static_cast<T*>(lua_touserdata(L, idx));
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

static int WeatherSystem_get_ActiveRegion(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushOpaquePointer(L, instance->ActiveRegion);
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

static int WeatherSystem_get_previousArea(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushOpaquePointer(L, instance->previousArea);
}

// AreaBiomeGroup is not bound yet, so this fixed array is a snapshot of borrowed opaque pointers.
static int WeatherSystem_get_areaGroups(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    const int count = (int)(sizeof(instance->areaGroups) / sizeof(instance->areaGroups[0]));
    lua_createtable(L, count, 0);
    for (int i = 0; i < count; ++i)
    {
        pushOpaquePointer(L, instance->areaGroups[i]);
        lua_rawseti(L, -2, i + 1);
    }
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

static int WeatherSystem_get_previousSector(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    return pushOpaquePointer(L, instance->previousSector);
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

// These registries are maintained by add/remove methods. Return snapshots so Lua cannot
// bypass the engine's registration and teardown paths by mutating the containers directly.
static int WeatherSystem_get_weatherListeners(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    WeatherListenerMap* listeners = &instance->weatherListeners;
    lua_createtable(L, (int)listeners->size(), 0);
    int index = 1;
    for (WeatherListenerMap::const_iterator it = listeners->begin(); it != listeners->end(); ++it, ++index)
    {
        lua_createtable(L, 0, 2);
        pushObject<WeatherRegion::Listener>(L, it->first, ListenerBinding::getMetatableName());
        lua_setfield(L, -2, "listener");
        pushObject<WeatherRegion>(L, it->second, WeatherRegionBinding::getMetatableName());
        lua_setfield(L, -2, "region");
        lua_rawseti(L, -2, index);
    }
    return 1;
}

static int WeatherSystem_get_activeEffects(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    WeatherEffectSet* effects = &instance->activeEffects;
    lua_createtable(L, (int)effects->size(), 0);
    int index = 1;
    for (WeatherEffectSet::const_iterator it = effects->begin(); it != effects->end(); ++it, ++index)
    {
        pushOpaquePointer(L, *it);
        lua_rawseti(L, -2, index);
    }
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

static int WeatherSystem_set_ActiveRegion(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->ActiveRegion = checkOpaquePointer<AreaBiomeGroup>(L, 2, "AreaBiomeGroup lightuserdata or nil expected", true);
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

static int WeatherSystem_set_previousArea(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->previousArea = checkOpaquePointer<AreaBiomeGroup>(L, 2, "AreaBiomeGroup lightuserdata or nil expected", true);
    return 0;
}

static int WeatherSystem_set_areaGroups(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    luaL_checktype(L, 2, LUA_TTABLE);

    AreaBiomeGroup* values[4];
    for (int i = 0; i < 4; ++i)
    {
        lua_rawgeti(L, 2, i + 1);
        if (!lua_isnoneornil(L, -1) && !lua_islightuserdata(L, -1))
            return luaL_error(L, "WeatherSystem.areaGroups[%d] must be AreaBiomeGroup lightuserdata or nil", i + 1);
        values[i] = static_cast<AreaBiomeGroup*>(lua_touserdata(L, -1));
        lua_pop(L, 1);
    }
    for (int i = 0; i < 4; ++i)
        instance->areaGroups[i] = values[i];
    return 0;
}

static int WeatherSystem_set_previousSector(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    instance->previousSector = checkOpaquePointer<AreaSector>(L, 2, "AreaSector lightuserdata or nil expected", true);
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

int WeatherSystemBinding::getPositionGlobalEffects(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!instance->ActiveRegion)
        return luaL_error(L, "WeatherSystem.getPositionGlobalEffects requires an active biome");

    Ogre::Vector3 position;
    if (!readVector3(L, 2, position)) return luaL_argerror(L, 2, "Vector3 table expected");
    const GlobalEffectList& effects = instance->getPositionGlobalEffects(position);
    lua_createtable(L, (int)effects.size(), 0);
    for (size_t i = 0; i < effects.size(); ++i)
    {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, (lua_Integer)effects[i].first);
        lua_setfield(L, -2, "effect");
        lua_pushnumber(L, effects[i].second);
        lua_setfield(L, -2, "strength");
        lua_rawseti(L, -2, (int)i + 1);
    }
    return 1;
}

int WeatherSystemBinding::addWeatherEffect(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!lua_islightuserdata(L, 2)) return luaL_argerror(L, 2, "EffectHandler lightuserdata expected");
    EffectHandler* effect = static_cast<EffectHandler*>(lua_touserdata(L, 2));
    instance->addWeatherEffect(effect);
    return 0;
}

int WeatherSystemBinding::removeWeatherEffect(lua_State* L)
{
    WeatherSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "WeatherSystem is nil");
    if (!lua_islightuserdata(L, 2)) return luaL_argerror(L, 2, "EffectHandler lightuserdata expected");
    EffectHandler* effect = static_cast<EffectHandler*>(lua_touserdata(L, 2));
    instance->removeWeatherEffect(effect);
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
  line 217: WeatherSystem() - constructor; getInstance creates the singleton

Read-only properties:
  weatherListeners, activeEffects - snapshots of engine registries; mutate them through add/remove methods
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
        { "getPositionGlobalEffects", WeatherSystemBinding::getPositionGlobalEffects },
        { "addWeatherEffect", WeatherSystemBinding::addWeatherEffect },
        { "removeWeatherEffect", WeatherSystemBinding::removeWeatherEffect },
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
    registerGetter(L, "ActiveRegion", WeatherSystem_get_ActiveRegion);
    registerGetter(L, "exitingBiome", WeatherSystem_get_exitingBiome);
    registerGetter(L, "previousBiomeAABB", WeatherSystem_get_previousBiomeAABB);
    registerGetter(L, "previousArea", WeatherSystem_get_previousArea);
    registerGetter(L, "areaGroups", WeatherSystem_get_areaGroups);
    registerGetter(L, "areaFog", WeatherSystem_get_areaFog);
    registerGetter(L, "previousSector", WeatherSystem_get_previousSector);
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
    registerGetter(L, "weatherListeners", WeatherSystem_get_weatherListeners);
    registerGetter(L, "activeEffects", WeatherSystem_get_activeEffects);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "ActiveRegionWeather", WeatherSystem_set_ActiveRegionWeather);
    registerSetter(L, "ActiveRegion", WeatherSystem_set_ActiveRegion);
    registerSetter(L, "exitingBiome", WeatherSystem_set_exitingBiome);
    registerSetter(L, "previousBiomeAABB", WeatherSystem_set_previousBiomeAABB);
    registerSetter(L, "previousArea", WeatherSystem_set_previousArea);
    registerSetter(L, "areaGroups", WeatherSystem_set_areaGroups);
    registerSetter(L, "previousSector", WeatherSystem_set_previousSector);
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
