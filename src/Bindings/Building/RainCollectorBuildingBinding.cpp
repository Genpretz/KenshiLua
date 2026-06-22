#include "pch.h"
#include "Bindings/Building/RainCollectorBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/RainCollectorBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static RainCollectorBuilding* getS(lua_State* L, int idx)
{
    return checkObject<RainCollectorBuilding>(L, idx, RainCollectorBuildingBinding::getMetatableName());
}

int RainCollectorBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int RainCollectorBuildingBinding::tostring(lua_State* L)
{
    RainCollectorBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int RainCollectorBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, RainCollectorBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    RainCollectorBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int RainCollectorBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    RainCollectorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "RainCollectorBuilding is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int RainCollectorBuildingBinding::calculateEfficiencyMult(lua_State* L)
{
    RainCollectorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = s->calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::_NV_calculateEfficiencyMult(lua_State* L)
{
    RainCollectorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = s->_NV_calculateEfficiencyMult();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::getRainAmount(lua_State* L)
{
    RainCollectorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "RainCollectorBuilding is nil");

    float result = s->getRainAmount();
    lua_pushnumber(L, result);
    return 1;
}

int RainCollectorBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    RainCollectorBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "RainCollectorBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: RainCollectorBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 14: void getGUIState(...) - unsupported arg type
  line 15: void _NV_getGUIState(...) - unsupported arg type
  line 16: void getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
  line 17: void _NV_getGUIToolTipForGroundResourceEfficiency(...) - unsupported arg type
*/

void RainCollectorBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RainCollectorBuildingBinding::gc },
        { "__tostring", RainCollectorBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "calculateEfficiencyMult", RainCollectorBuildingBinding::calculateEfficiencyMult },
        { "_NV_calculateEfficiencyMult", RainCollectorBuildingBinding::_NV_calculateEfficiencyMult },
        { "getRainAmount", RainCollectorBuildingBinding::getRainAmount },
        { "_DESTRUCTOR", RainCollectorBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, RainCollectorBuildingBinding::getMetatableName(), meta, methods, RainCollectorBuildingBinding::index, RainCollectorBuildingBinding::newindex);
}

} // namespace KenshiLua