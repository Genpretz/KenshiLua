#include "pch.h"
#include "Bindings/Building/GatewayBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/GatewayBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static GatewayBuilding* getS(lua_State* L, int idx)
{
    return checkObject<GatewayBuilding>(L, idx, GatewayBuildingBinding::getMetatableName());
}

int GatewayBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int GatewayBuildingBinding::tostring(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int GatewayBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GatewayBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GatewayBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int GatewayBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int GatewayBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int GatewayBuildingBinding::reAnnounceGateToPathfinder(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->reAnnounceGateToPathfinder();
    return 0;
}

int GatewayBuildingBinding::postCreationPathfinderSetupStuff(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->postCreationPathfinderSetupStuff();
    return 0;
}

int GatewayBuildingBinding::_NV_postCreationPathfinderSetupStuff(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->_NV_postCreationPathfinderSetupStuff();
    return 0;
}

int GatewayBuildingBinding::isForSale(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    bool result = s->isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GatewayBuildingBinding::_NV_isForSale(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    bool result = s->_NV_isForSale();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GatewayBuildingBinding::setup(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->setup();
    return 0;
}

int GatewayBuildingBinding::_NV_setup(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    s->_NV_setup();
    return 0;
}

int GatewayBuildingBinding::getOutsideGateCode(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    int result = s->getOutsideGateCode();
    lua_pushinteger(L, result);
    return 1;
}

int GatewayBuildingBinding::separatesAreas(lua_State* L)
{
    GatewayBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GatewayBuilding is nil");

    bool result = s->separatesAreas();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 13: GatewayBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 17: void setHandle(...) - unsupported arg type
  line 18: void _NV_setHandle(...) - unsupported arg type
  line 19: Ogre::Vector3 getPositionForWaypoint(...) - unsupported return type
  line 20: Ogre::Vector3 _NV_getPositionForWaypoint(...) - unsupported return type
  line 21: UseableStuff* getUseableStuff(...) - unsupported return type
  line 22: UseableStuff* _NV_getUseableStuff(...) - unsupported return type
  line 23: GatewayBuilding* isGate(...) - unsupported return type
  line 24: GatewayBuilding* _NV_isGate(...) - unsupported return type
  line 29: int getGateCodeAt(...) - unsupported arg type
*/

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
        { "isForSale", GatewayBuildingBinding::isForSale },
        { "_NV_isForSale", GatewayBuildingBinding::_NV_isForSale },
        { "setup", GatewayBuildingBinding::setup },
        { "_NV_setup", GatewayBuildingBinding::_NV_setup },
        { "getOutsideGateCode", GatewayBuildingBinding::getOutsideGateCode },
        { "separatesAreas", GatewayBuildingBinding::separatesAreas },
        { 0, 0 }
    };
    registerClass(L, GatewayBuildingBinding::getMetatableName(), meta, methods, GatewayBuildingBinding::index, GatewayBuildingBinding::newindex);
}

} // namespace KenshiLua