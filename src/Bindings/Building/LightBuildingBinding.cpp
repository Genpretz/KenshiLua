#include "pch.h"
#include <kenshi/Building/LightBuilding.h>
#include "LightBuildingBinding.h"
#include "UseableStuffBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static LightBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<LightBuilding>(L, idx, LightBuildingBinding::getMetatableName());
}

// --- Getters for LightBuilding ---
static int LightBuilding_get_mountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");
    // TODO: Unsupported type for mountedBuilding (hand)
    lua_pushnil(L);
    return 1;
}

// --- Setters for LightBuilding ---
static int LightBuilding_set_mountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");
    return luaL_error(L, "Read-only or unsupported setter type for mountedBuilding");
}

// --- Methods for LightBuilding
int LightBuildingBinding::createPhysical(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_createPhysical(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::getMouseCursor(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int LightBuildingBinding::_NV_getMouseCursor(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int LightBuildingBinding::needPowerRightNow(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_needPowerRightNow(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->_NV_needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::getPositionMarker(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int LightBuildingBinding::_NV_getPositionMarker(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->_NV_getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int LightBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: LightBuilding* _CONSTRUCTOR(...) - unsupported arg type
  line 12: GameSaveState serialise(...) - unsupported return type
  line 13: GameSaveState _NV_serialise(...) - unsupported return type
  line 14: void loadFromSerialise(...) - unsupported arg type
  line 15: void _NV_loadFromSerialise(...) - unsupported arg type
  line 22: const hand& getMountedBuilding(...) - reference return type
  line 23: const hand& _NV_getMountedBuilding(...) - reference return type
  line 24: void setMountedBuilding(...) - unsupported arg type
*/

int LightBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LightBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LightBuilding object");
    return 1;
}

void LightBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LightBuildingBinding::gc },
        { "__tostring", LightBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "createPhysical", LightBuildingBinding::createPhysical },
        { "_NV_createPhysical", LightBuildingBinding::_NV_createPhysical },
        { "getMouseCursor", LightBuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", LightBuildingBinding::_NV_getMouseCursor },
        { "needPowerRightNow", LightBuildingBinding::needPowerRightNow },
        { "_NV_needPowerRightNow", LightBuildingBinding::_NV_needPowerRightNow },
        { "getPositionMarker", LightBuildingBinding::getPositionMarker },
        { "_NV_getPositionMarker", LightBuildingBinding::_NV_getPositionMarker },
        { "_DESTRUCTOR", LightBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        LightBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LightBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, LightBuilding_get_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, LightBuilding_set_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // setMetatableParent(L, LightBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
