#include "pch.h"
#include "Bindings/WindGeneratorBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/GeneratorBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static WindGeneratorBuilding* getS(lua_State* L, int idx)
{
    return checkObject<WindGeneratorBuilding>(L, idx, WindGeneratorBuildingBinding::getMetatableName());
}

int WindGeneratorBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int WindGeneratorBuildingBinding::tostring(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int WindGeneratorBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, WindGeneratorBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int WindGeneratorBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int WindGeneratorBuildingBinding::getPowerOutput(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = s->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_getPowerOutput(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = s->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::getSoundIntensity(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = s->getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_getSoundIntensity(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    float result = s->_NV_getSoundIntensity();
    lua_pushnumber(L, result);
    return 1;
}

int WindGeneratorBuildingBinding::isAnyInputsEmpty(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    bool result = s->isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WindGeneratorBuildingBinding::_NV_isAnyInputsEmpty(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    bool result = s->_NV_isAnyInputsEmpty();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int WindGeneratorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    WindGeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "WindGeneratorBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 32: WindGeneratorBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 35: void getGUIState(...) - unsupported arg type
  line 36: void _NV_getGUIState(...) - unsupported arg type
  line 37: void getGUIPower(...) - unsupported arg type
  line 38: void _NV_getGUIPower(...) - unsupported arg type
*/

void WindGeneratorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       WindGeneratorBuildingBinding::gc },
        { "__tostring", WindGeneratorBuildingBinding::tostring },
        { "__index",    WindGeneratorBuildingBinding::index },
        { "__newindex", WindGeneratorBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getPowerOutput", WindGeneratorBuildingBinding::getPowerOutput },
        { "_NV_getPowerOutput", WindGeneratorBuildingBinding::_NV_getPowerOutput },
        { "getSoundIntensity", WindGeneratorBuildingBinding::getSoundIntensity },
        { "_NV_getSoundIntensity", WindGeneratorBuildingBinding::_NV_getSoundIntensity },
        { "isAnyInputsEmpty", WindGeneratorBuildingBinding::isAnyInputsEmpty },
        { "_NV_isAnyInputsEmpty", WindGeneratorBuildingBinding::_NV_isAnyInputsEmpty },
        { "_DESTRUCTOR", WindGeneratorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, WindGeneratorBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua