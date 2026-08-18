#include "pch.h"
#include "kenshi\Town.h"
#include "TownBuildingsManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/TownBuildingsManager_BuildingInfoBinding.h"
#include "Bindings/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

static TownBuildingsManager* getInstance(lua_State* L, int idx)
{
    return checkObject<TownBuildingsManager>(L, idx, TownBuildingsManagerBinding::getMetatableName());
}

// --- Getters for TownBuildingsManager ---
static int TownBuildingsManager_get_signsVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    lua_pushboolean(L, instance->signsVisible ? 1 : 0);
    return 1;
}

static int TownBuildingsManager_get_town(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    return pushObject<TownBase>(L, instance->town, TownBaseBinding::getMetatableName());
}

// --- Setters for TownBuildingsManager ---
static int TownBuildingsManager_set_signsVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    instance->signsVisible = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TownBuildingsManager_set_town(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    instance->town = lua_isnoneornil(L, 2) ? nullptr : checkObject<TownBase>(L, 2, TownBaseBinding::getMetatableName());
    return 0;
}

int TownBuildingsManagerBinding::clear(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    instance->clear();
    return 0;
}

int TownBuildingsManagerBinding::moveBuildingsTo(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    TownBuildingsManager* to = checkObject<TownBuildingsManager>(L, 2, TownBuildingsManagerBinding::getMetatableName());
    instance->moveBuildingsTo(to);
    return 0;
}

int TownBuildingsManagerBinding::removeBuilding(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    instance->removeBuilding(building);
    return 0;
}

int TownBuildingsManagerBinding::setFloorVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    int floor = (int)luaL_checkinteger(L, 3);
    instance->setFloorVisible(building, floor);
    return 0;
}

int TownBuildingsManagerBinding::setAllVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    int floor = (int)luaL_checkinteger(L, 2);
    bool onlyPlayerBuildings = lua_toboolean(L, 3) != 0;
    instance->setAllVisible(floor, onlyPlayerBuildings);
    return 0;
}

int TownBuildingsManagerBinding::resetAllVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    instance->resetAllVisible();
    return 0;
}

int TownBuildingsManagerBinding::setSignsVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    bool value = lua_toboolean(L, 2) != 0;
    instance->setSignsVisible(value);
    return 0;
}

int TownBuildingsManagerBinding::factoryObjectCreatedCallback(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    RootObject* _a1 = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->factoryObjectCreatedCallback(_a1);
    return 0;
}

int TownBuildingsManagerBinding::_NV_factoryObjectCreatedCallback(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    RootObject* _a1 = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_factoryObjectCreatedCallback(_a1);
    return 0;
}

int TownBuildingsManagerBinding::getFloorVisible(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");

    Building* building = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    if (lua_gettop(L) >= 3)
    {
        int floor = (int)luaL_checkinteger(L, 3);
        bool result = instance->getFloorVisible(building, floor);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }
    else
    {
        int result = instance->getFloorVisible(building);
        lua_pushinteger(L, result);
        return 1;
    }
}

/*
Skipped methods needing manual binding:
  line 73: Ogre::MovableObject* addEntity(...) - unsupported arg type
  line 74: bool removeEntity(...) - static method
  line 75: void removeEntity(...) - overloaded method
  line 77: bool switchInstancing(...) - unsupported arg type
  line 78: void addInteriorShell(...) - unsupported arg type
  line 79: void removeInteriorShell(...) - unsupported arg type
  line 88: bool isInstanced(...) - static method
  line 89: bool isEntity(...) - static method
  line 90: bool makeInstance(...) - unsupported arg type
  line 91: bool makeEntity(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 92: buildingEntities (ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>::type) - unsupported type
  line 93: instancesManagers (boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 94: signs (Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >) - unsupported type
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



static int TownBuildingsManager_get_buildingEntities(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    return pushObject<OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo>::MapType>(
        L, &instance->buildingEntities,
        OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo>::metaName
    );
}


static int TownBuildingsManager_get_instancesManagers(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for instancesManagers (boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >)
    return luaL_error(L, "Unsupported property 'instancesManagers' (type: boost::unordered::unordered_map<std::string, Ogre::InstanceManager*, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::pair<std::string const, Ogre::InstanceManager*>, Ogre::GeneralAllocPolicy > >)");
}


static int TownBuildingsManager_get_signs(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    // TODO: Unsupported type for signs (Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >)
    return luaL_error(L, "Unsupported property 'signs' (type: Ogre::FastArray<std::pair<Building*, Ogre::Entity*> >)");
}


static int TownBuildingsManager_set_buildingEntities(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    auto* val = OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo>::get(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'buildingEntities' must be ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>");
    instance->buildingEntities = *val;
    return 0;
}


static int TownBuildingsManager_set_instancesManagers(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for instancesManagers");
}


static int TownBuildingsManager_set_signs(lua_State* L)
{
    TownBuildingsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TownBuildingsManager is nil");
    return luaL_error(L, "Read-only or unsupported setter type for signs");
}


void TownBuildingsManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TownBuildingsManagerBinding::gc },
        { "__tostring", TownBuildingsManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "clear", TownBuildingsManagerBinding::clear },
        { "moveBuildingsTo", TownBuildingsManagerBinding::moveBuildingsTo },
        { "removeBuilding", TownBuildingsManagerBinding::removeBuilding },
        { "setFloorVisible", TownBuildingsManagerBinding::setFloorVisible },
        { "setAllVisible", TownBuildingsManagerBinding::setAllVisible },
        { "resetAllVisible", TownBuildingsManagerBinding::resetAllVisible },
        { "setSignsVisible", TownBuildingsManagerBinding::setSignsVisible },
        { "factoryObjectCreatedCallback", TownBuildingsManagerBinding::factoryObjectCreatedCallback },
        { "_NV_factoryObjectCreatedCallback", TownBuildingsManagerBinding::_NV_factoryObjectCreatedCallback },
        { "getFloorVisible", TownBuildingsManagerBinding::getFloorVisible },
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
    registerGetter(L, "signsVisible", TownBuildingsManager_get_signsVisible);
    registerGetter(L, "town", TownBuildingsManager_get_town);
    registerGetter(L, "buildingEntities", TownBuildingsManager_get_buildingEntities);
    registerGetter(L, "instancesManagers", TownBuildingsManager_get_instancesManagers);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "signsVisible", TownBuildingsManager_set_signsVisible);
    registerSetter(L, "town", TownBuildingsManager_set_town);
    registerSetter(L, "buildingEntities", TownBuildingsManager_set_buildingEntities);
    registerSetter(L, "instancesManagers", TownBuildingsManager_set_instancesManagers);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to FactoryCallbackInterface
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, TownBuildingsManagerBinding::getMetatableName(), FactoryCallbackInterfaceBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    OgreUnorderedMapBinding<Building*, TownBuildingsManager::BuildingInfo>::registerBinding(
        L, 
        "ogre_unordered_map<Building*, TownBuildingsManager::BuildingInfo>", 
        BuildingBinding::getMetatableName(), 
        TownBuildingsManager_BuildingInfoBinding::getMetatableName()
    );
}

} // namespace KenshiLua