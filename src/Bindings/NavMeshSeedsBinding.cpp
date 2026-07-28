#include "pch.h"
#include "kenshi\navmeshgenerator.h"
#include "NavMeshSeedsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ZoneMapBinding.h"

namespace KenshiLua
{

static NavMeshSeeds* getInstance(lua_State* L, int idx)
{
    return checkObject<NavMeshSeeds>(L, idx, NavMeshSeedsBinding::getMetatableName());
}

// --- Getters for NavMeshSeeds ---
// --- Setters for NavMeshSeeds ---
int NavMeshSeedsBinding::load(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    instance->load();
    return 0;
}

int NavMeshSeedsBinding::save(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    instance->save();
    return 0;
}

int NavMeshSeedsBinding::addSeedPoint(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    bool terrain = lua_toboolean(L, 3) != 0;
    instance->addSeedPoint(p, terrain);
    return 0;
}

int NavMeshSeedsBinding::removeSeedPoints(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float radius = (float)luaL_checknumber(L, 3);
    int result = instance->removeSeedPoints(pos, radius);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshSeedsBinding::clearSeedPoints(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    int result = instance->clearSeedPoints(zone);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshSeedsBinding::removeIsland(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    Ogre::Vector3 pos;
    readVector3(L, 2, pos);
    float radius = (float)luaL_checknumber(L, 3);
    int result = instance->removeIsland(pos, radius);
    lua_pushinteger(L, result);
    return 1;
}

int NavMeshSeedsBinding::projectToTerrain(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->projectToTerrain(zone);
    return 0;
}

int NavMeshSeedsBinding::getSeedPoints(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    const lektor<Ogre::Vector3>* result = instance->getSeedPoints(zone);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int NavMeshSeedsBinding::_CONSTRUCTOR(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    NavMeshSeeds* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int NavMeshSeedsBinding::_DESTRUCTOR(lua_State* L)
{
    NavMeshSeeds* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "NavMeshSeeds is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - NavMeshSeedsBinding::getSeedPoints: const lektor<Ogre::Vector3>* (unbound pointer)
  - NavMeshSeedsBinding::_CONSTRUCTOR: NavMeshSeeds* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 12: seedPoints (std::map<ZoneMap*, lektor<Ogre::Vector3>, std::less<ZoneMap*>, Ogre::STLAllocator<std::pair<ZoneMap*const, lektor<Ogre::Vector3> >, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int NavMeshSeedsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int NavMeshSeedsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.NavMeshSeeds object");
    return 1;
}

void NavMeshSeedsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       NavMeshSeedsBinding::gc },
        { "__tostring", NavMeshSeedsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "load", NavMeshSeedsBinding::load },
        { "save", NavMeshSeedsBinding::save },
        { "addSeedPoint", NavMeshSeedsBinding::addSeedPoint },
        { "removeSeedPoints", NavMeshSeedsBinding::removeSeedPoints },
        { "clearSeedPoints", NavMeshSeedsBinding::clearSeedPoints },
        { "removeIsland", NavMeshSeedsBinding::removeIsland },
        { "projectToTerrain", NavMeshSeedsBinding::projectToTerrain },
        { "getSeedPoints", NavMeshSeedsBinding::getSeedPoints },
        { "_CONSTRUCTOR", NavMeshSeedsBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", NavMeshSeedsBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        NavMeshSeedsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, NavMeshSeedsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua