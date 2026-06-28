#include "pch.h"
#include "kenshi\Town.h"
#include "TownBuildingsManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TownBuildingsManager* getB(lua_State* L, int idx)
{
    return checkObject<TownBuildingsManager>(L, idx, TownBuildingsManagerBinding::getMetatableName());
}

// --- Getters for TownBuildingsManager ---
static int TownBuildingsManager_get_buildingEntities(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for buildingEntities (ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type)
    return luaL_error(L, "Unsupported property 'buildingEntities' (type: ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type)");
}

static int TownBuildingsManager_get_instancesManagers(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for instancesManagers (boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'instancesManagers' (type: boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >)");
}

static int TownBuildingsManager_get_signs(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for signs (Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >)
    return luaL_error(L, "Unsupported property 'signs' (type: Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >)");
}

static int TownBuildingsManager_get_signsVisible(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    lua_pushboolean(L, b->signsVisible ? 1 : 0);
    return 1;
}

static int TownBuildingsManager_get_town(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for town (TownBase*)
    return luaL_error(L, "Unsupported property 'town' (type: TownBase*)");
}

// --- Setters for TownBuildingsManager ---
static int TownBuildingsManager_set_buildingEntities(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for buildingEntities");
}

static int TownBuildingsManager_set_instancesManagers(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for instancesManagers");
}

static int TownBuildingsManager_set_signs(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for signs");
}

static int TownBuildingsManager_set_signsVisible(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    b->signsVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBuildingsManager_set_town(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for town");
}

int TownBuildingsManagerBinding::_DESTRUCTOR(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");

    b->_DESTRUCTOR();
    return 0;
}

int TownBuildingsManagerBinding::clear(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");

    b->clear();
    return 0;
}

int TownBuildingsManagerBinding::setAllVisible(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool onlyPlayerBuildings = lua_toboolean(L, 3) != 0;
    b->setAllVisible(floor, onlyPlayerBuildings);
    return 0;
}

int TownBuildingsManagerBinding::resetAllVisible(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");

    b->resetAllVisible();
    return 0;
}

int TownBuildingsManagerBinding::setSignsVisible(lua_State* L)
{
    TownBuildingsManager* b = getB(L, 1);
    if (!b) return luaL_error(L, "TownBuildingsManager is nil");

    bool value = lua_toboolean(L, 2) != 0;
    b->setSignsVisible(value);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 68: TownBuildingsManager* _CONSTRUCTOR(...) - unsupported return type
  line 72: void moveBuildingsTo(...) - unsupported arg type
  line 73: Ogre::MovableObject* addEntity(...) - unsupported return type
  line 74: bool removeEntity(...) - static method
  line 75: void removeEntity(...) - overloaded method
  line 76: void removeBuilding(...) - unsupported arg type
  line 77: bool switchInstancing(...) - unsupported arg type
  line 78: void addInteriorShell(...) - unsupported arg type
  line 79: void removeInteriorShell(...) - unsupported arg type
  line 80: void setFloorVisible(...) - unsupported arg type
  line 81: int getFloorVisible(...) - overloaded method
  line 82: bool getFloorVisible(...) - overloaded method
  line 86: void factoryObjectCreatedCallback(...) - unsupported arg type
  line 87: void _NV_factoryObjectCreatedCallback(...) - unsupported arg type
  line 88: bool isInstanced(...) - static method
  line 89: bool isEntity(...) - static method
  line 90: bool makeInstance(...) - unsupported arg type
  line 91: bool makeEntity(...) - unsupported arg type
*/

int TownBuildingsManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TownBuildingsManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TownBuildingsManager object");
    return 1;
}

void TownBuildingsManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBuildingsManagerBinding::gc },
        { "__tostring", TownBuildingsManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", TownBuildingsManagerBinding::_DESTRUCTOR },
        { "clear", TownBuildingsManagerBinding::clear },
        { "setAllVisible", TownBuildingsManagerBinding::setAllVisible },
        { "resetAllVisible", TownBuildingsManagerBinding::resetAllVisible },
        { "setSignsVisible", TownBuildingsManagerBinding::setSignsVisible },
        { 0, 0 }
    };

    registerClass(
        L, 
        TownBuildingsManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TownBuildingsManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TownBuildingsManager_get_buildingEntities);
    lua_setfield(L, -2, "buildingEntities");
    lua_pushcfunction(L, TownBuildingsManager_get_instancesManagers);
    lua_setfield(L, -2, "instancesManagers");
    lua_pushcfunction(L, TownBuildingsManager_get_signs);
    lua_setfield(L, -2, "signs");
    lua_pushcfunction(L, TownBuildingsManager_get_signsVisible);
    lua_setfield(L, -2, "signsVisible");
    lua_pushcfunction(L, TownBuildingsManager_get_town);
    lua_setfield(L, -2, "town");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TownBuildingsManager_set_buildingEntities);
    lua_setfield(L, -2, "buildingEntities");
    lua_pushcfunction(L, TownBuildingsManager_set_instancesManagers);
    lua_setfield(L, -2, "instancesManagers");
    lua_pushcfunction(L, TownBuildingsManager_set_signs);
    lua_setfield(L, -2, "signs");
    lua_pushcfunction(L, TownBuildingsManager_set_signsVisible);
    lua_setfield(L, -2, "signsVisible");
    lua_pushcfunction(L, TownBuildingsManager_set_town);
    lua_setfield(L, -2, "town");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua