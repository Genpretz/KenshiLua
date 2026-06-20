#include "pch.h"
#include "Bindings/GeneratorBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/GeneratorBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static GeneratorBuilding* getS(lua_State* L, int idx)
{
    return checkObject<GeneratorBuilding>(L, idx, GeneratorBuildingBinding::getMetatableName());
}

int GeneratorBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int GeneratorBuildingBinding::tostring(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int GeneratorBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, GeneratorBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    GeneratorBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int GeneratorBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int GeneratorBuildingBinding::getPowerOutput(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");

    float result = s->getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_NV_getPowerOutput(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");

    float result = s->_NV_getPowerOutput();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::getFuelConsumptionRate(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");

    float result = s->getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_NV_getFuelConsumptionRate(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");

    float result = s->_NV_getFuelConsumptionRate();
    lua_pushnumber(L, result);
    return 1;
}

int GeneratorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    GeneratorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "GeneratorBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: GeneratorBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 14: void getGUIState(...) - unsupported arg type
  line 15: void _NV_getGUIState(...) - unsupported arg type
  line 16: float getInputValue(...) - unsupported arg type
  line 17: float _NV_getInputValue(...) - unsupported arg type
*/

void GeneratorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GeneratorBuildingBinding::gc },
        { "__tostring", GeneratorBuildingBinding::tostring },
        { "__index",    GeneratorBuildingBinding::index },
        { "__newindex", GeneratorBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "getPowerOutput", GeneratorBuildingBinding::getPowerOutput },
        { "_NV_getPowerOutput", GeneratorBuildingBinding::_NV_getPowerOutput },
        { "getFuelConsumptionRate", GeneratorBuildingBinding::getFuelConsumptionRate },
        { "_NV_getFuelConsumptionRate", GeneratorBuildingBinding::_NV_getFuelConsumptionRate },
        { "_DESTRUCTOR", GeneratorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, GeneratorBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua