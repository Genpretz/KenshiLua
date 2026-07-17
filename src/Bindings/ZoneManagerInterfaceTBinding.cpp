#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "ZoneManagerInterfaceTBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ZoneManagerInterfaceT* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneManagerInterfaceT>(L, idx, ZoneManagerInterfaceTBinding::getMetatableName());
}

// --- Getters for ZoneManagerInterfaceT ---
// --- Setters for ZoneManagerInterfaceT ---
int ZoneManagerInterfaceTBinding::isZoneLoadedT(lua_State* L)
{
    ZoneManagerInterfaceT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManagerInterfaceT is nil");

    Ogre::Vector3 _a1;
    readVector3(L, 2, _a1);
    bool result = instance->isZoneLoadedT(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerInterfaceTBinding::isZoneBeingLoadedT(lua_State* L)
{
    ZoneManagerInterfaceT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManagerInterfaceT is nil");

    Ogre::Vector3 _a1;
    readVector3(L, 2, _a1);
    bool result = instance->isZoneBeingLoadedT(_a1);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneManagerInterfaceTBinding::_CONSTRUCTOR(lua_State* L)
{
    ZoneManagerInterfaceT* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneManagerInterfaceT is nil");

    ZoneManagerInterfaceT* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 55: AABB2D getZoneBoundsT(...) - overloaded method
  line 56: AABB2D getZoneBoundsT(...) - overloaded method
  line 57: void getAllActiveZonesT(...) - unsupported arg type
*/

int ZoneManagerInterfaceTBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ZoneManagerInterfaceTBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneManagerInterfaceT object");
    return 1;
}

void ZoneManagerInterfaceTBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneManagerInterfaceTBinding::gc },
        { "__tostring", ZoneManagerInterfaceTBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isZoneLoadedT", ZoneManagerInterfaceTBinding::isZoneLoadedT },
        { "isZoneBeingLoadedT", ZoneManagerInterfaceTBinding::isZoneBeingLoadedT },
        { "_CONSTRUCTOR", ZoneManagerInterfaceTBinding::_CONSTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        ZoneManagerInterfaceTBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneManagerInterfaceTBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua