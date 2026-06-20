#include "pch.h"
#include "Bindings/LightBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/LightBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static LightBuilding* getS(lua_State* L, int idx)
{
    return checkObject<LightBuilding>(L, idx, LightBuildingBinding::getMetatableName());
}

int LightBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int LightBuildingBinding::tostring(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int LightBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, LightBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    LightBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO hand mountedBuilding; unsupported __index type from header line 27

    lua_pushnil(L);
    return 1;
}

int LightBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    // TODO hand mountedBuilding; unsupported __newindex type from header line 27

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int LightBuildingBinding::createPhysical(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    bool result = s->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_createPhysical(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    bool result = s->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::needPowerRightNow(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    bool result = s->needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_needPowerRightNow(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    bool result = s->_NV_needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    LightBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "LightBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: LightBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 12: GameSaveState serialise(...) - unsupported return type
  line 13: GameSaveState _NV_serialise(...) - unsupported return type
  line 14: void loadFromSerialise(...) - unsupported arg type
  line 15: void _NV_loadFromSerialise(...) - unsupported arg type
  line 18: CursorType getMouseCursor(...) - unsupported return type
  line 19: CursorType _NV_getMouseCursor(...) - unsupported return type
  line 22: const hand& getMountedBuilding(...) - reference return type
  line 23: const hand& _NV_getMountedBuilding(...) - reference return type
  line 24: void setMountedBuilding(...) - unsupported arg type
  line 25: Ogre::Vector3 getPositionMarker(...) - unsupported return type
  line 26: Ogre::Vector3 _NV_getPositionMarker(...) - unsupported return type
*/

void LightBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LightBuildingBinding::gc },
        { "__tostring", LightBuildingBinding::tostring },
        { "__index",    LightBuildingBinding::index },
        { "__newindex", LightBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "createPhysical", LightBuildingBinding::createPhysical },
        { "_NV_createPhysical", LightBuildingBinding::_NV_createPhysical },
        { "needPowerRightNow", LightBuildingBinding::needPowerRightNow },
        { "_NV_needPowerRightNow", LightBuildingBinding::_NV_needPowerRightNow },
        { "_DESTRUCTOR", LightBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, LightBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua