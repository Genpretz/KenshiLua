#include "pch.h"
#include <kenshi/Building/GatewayBuilding.h>
#include "GatewayBuildingBinding.h"
#include "BuildingBinding.h"
#include "UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static GatewayBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<GatewayBuilding>(L, idx, GatewayBuildingBinding::getMetatableName());
}

// --- Getters for GatewayBuilding ---
// --- Setters for GatewayBuilding ---
// --- Methods for GatewayBuilding ---
int GatewayBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int GatewayBuildingBinding::reAnnounceGateToPathfinder(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->reAnnounceGateToPathfinder();
    return 0;
}

int GatewayBuildingBinding::postCreationPathfinderSetupStuff(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->postCreationPathfinderSetupStuff();
    return 0;
}

int GatewayBuildingBinding::_NV_postCreationPathfinderSetupStuff(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->_NV_postCreationPathfinderSetupStuff();
    return 0;
}

int GatewayBuildingBinding::getPositionForWaypoint(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int GatewayBuildingBinding::_NV_getPositionForWaypoint(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    Ogre::Vector3 from;
    readVector3(L, 2, from);
    Ogre::Vector3 result = instance->_NV_getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

int GatewayBuildingBinding::getUseableStuff(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    UseableStuff* result = instance->getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int GatewayBuildingBinding::_NV_getUseableStuff(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    UseableStuff* result = instance->_NV_getUseableStuff();
    return pushObject<UseableStuff>(L, result, UseableStuffBinding::getMetatableName());
}

int GatewayBuildingBinding::isGate(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    GatewayBuilding* result = instance->isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int GatewayBuildingBinding::_NV_isGate(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    GatewayBuilding* result = instance->_NV_isGate();
    return pushObject<GatewayBuilding>(L, result, GatewayBuildingBinding::getMetatableName());
}

int GatewayBuildingBinding::isForSale(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    bool result = instance->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GatewayBuildingBinding::_NV_isForSale(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    bool result = instance->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GatewayBuildingBinding::setup(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->setup();
    return 0;
}

int GatewayBuildingBinding::_NV_setup(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    instance->_NV_setup();
    return 0;
}

int GatewayBuildingBinding::getGateCodeAt(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int result = instance->getGateCodeAt(p);
    lua_pushinteger(L, result);
    return 1;
}

int GatewayBuildingBinding::getOutsideGateCode(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    int result = instance->getOutsideGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int GatewayBuildingBinding::separatesAreas(lua_State* L)
{
    GatewayBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GatewayBuilding is nil");

    bool result = instance->separatesAreas();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 13: GatewayBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 17: void setHandle(...) - unsupported arg type
  line 18: void _NV_setHandle(...) - unsupported arg type
*/

int GatewayBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GatewayBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GatewayBuilding object");
    return 1;
}

void GatewayBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GatewayBuildingBinding::gc },
        { "__tostring", GatewayBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", GatewayBuildingBinding::_DESTRUCTOR },
        { "reAnnounceGateToPathfinder", GatewayBuildingBinding::reAnnounceGateToPathfinder },
        { "postCreationPathfinderSetupStuff", GatewayBuildingBinding::postCreationPathfinderSetupStuff },
        { "_NV_postCreationPathfinderSetupStuff", GatewayBuildingBinding::_NV_postCreationPathfinderSetupStuff },
        { "getPositionForWaypoint", GatewayBuildingBinding::getPositionForWaypoint },
        { "_NV_getPositionForWaypoint", GatewayBuildingBinding::_NV_getPositionForWaypoint },
        { "getUseableStuff", GatewayBuildingBinding::getUseableStuff },
        { "_NV_getUseableStuff", GatewayBuildingBinding::_NV_getUseableStuff },
        { "isGate", GatewayBuildingBinding::isGate },
        { "_NV_isGate", GatewayBuildingBinding::_NV_isGate },
        { "isForSale", GatewayBuildingBinding::isForSale },
        { "_NV_isForSale", GatewayBuildingBinding::_NV_isForSale },
        { "setup", GatewayBuildingBinding::setup },
        { "_NV_setup", GatewayBuildingBinding::_NV_setup },
        { "getGateCodeAt", GatewayBuildingBinding::getGateCodeAt },
        { "getOutsideGateCode", GatewayBuildingBinding::getOutsideGateCode },
        { "separatesAreas", GatewayBuildingBinding::separatesAreas },
        { 0, 0 }
    };

    registerClass(
        L, 
        GatewayBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GatewayBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Building
    setMetatableParent(L, GatewayBuildingBinding::getMetatableName(), BuildingBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua