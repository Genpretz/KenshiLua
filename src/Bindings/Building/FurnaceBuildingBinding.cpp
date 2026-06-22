#include "pch.h"
#include "Bindings/Building/FurnaceBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/FurnaceBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static FurnaceBuilding* getS(lua_State* L, int idx)
{
    return checkObject<FurnaceBuilding>(L, idx, FurnaceBuildingBinding::getMetatableName());
}

int FurnaceBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int FurnaceBuildingBinding::tostring(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int FurnaceBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, FurnaceBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    FurnaceBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "active") == 0) { lua_pushboolean(L, s->active ? 1 : 0); return 1; }

    lua_pushnil(L);
    return 1;
}

int FurnaceBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    if (strcmp(key, "active") == 0) { s->active = lua_toboolean(L, 3) != 0; return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int FurnaceBuildingBinding::setupFromData(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    s->setupFromData();
    return 0;
}

int FurnaceBuildingBinding::_NV_setupFromData(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    s->_NV_setupFromData();
    return 0;
}

int FurnaceBuildingBinding::getInputValueTotal(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    float result = s->getInputValueTotal();
    lua_pushnumber(L, result);
    return 1;
}

int FurnaceBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int FurnaceBuildingBinding::updateInputs(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->updateInputs(rate);
    return 0;
}

int FurnaceBuildingBinding::_NV_updateInputs(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->_NV_updateInputs(rate);
    return 0;
}

int FurnaceBuildingBinding::updateOutput(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->updateOutput(rate);
    return 0;
}

int FurnaceBuildingBinding::_NV_updateOutput(lua_State* L)
{
    FurnaceBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceBuilding is nil");

    float rate = (float)luaL_checknumber(L, 2);
    s->_NV_updateOutput(rate);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 25: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 26: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 29: void getGUIData(...) - unsupported arg type
  line 30: void _NV_getGUIData(...) - unsupported arg type
  line 32: float getInputValue(...) - unsupported arg type
  line 33: float _NV_getInputValue(...) - unsupported arg type
  line 34: TaskType getDefaultTask(...) - unsupported return type
  line 35: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 36: void getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 37: void _NV_getResourcesNeededBecauseNotFull(...) - unsupported arg type
  line 38: void getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 39: void _NV_getResourcesNeededBecauseEmpty(...) - unsupported arg type
  line 40: bool canHaveSomeOfThese(...) - unsupported arg type
  line 41: bool _NV_canHaveSomeOfThese(...) - unsupported arg type
  line 42: void incinerate(...) - unsupported arg type
  line 45: FurnaceBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 48: void operate(...) - unsupported arg type
  line 49: void _NV_operate(...) - unsupported arg type
  line 54: bool limitInputsOutputRate(...) - non-string reference arg
  line 55: bool _NV_limitInputsOutputRate(...) - non-string reference arg
  line 56: float getIronAmountInItem(...) - unsupported arg type
*/

void FurnaceBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FurnaceBuildingBinding::gc },
        { "__tostring", FurnaceBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setupFromData", FurnaceBuildingBinding::setupFromData },
        { "_NV_setupFromData", FurnaceBuildingBinding::_NV_setupFromData },
        { "getInputValueTotal", FurnaceBuildingBinding::getInputValueTotal },
        { "_DESTRUCTOR", FurnaceBuildingBinding::_DESTRUCTOR },
        { "updateInputs", FurnaceBuildingBinding::updateInputs },
        { "_NV_updateInputs", FurnaceBuildingBinding::_NV_updateInputs },
        { "updateOutput", FurnaceBuildingBinding::updateOutput },
        { "_NV_updateOutput", FurnaceBuildingBinding::_NV_updateOutput },
        { 0, 0 }
    };
    registerClass(L, FurnaceBuildingBinding::getMetatableName(), meta, methods, FurnaceBuildingBinding::index, FurnaceBuildingBinding::newindex);
}

} // namespace KenshiLua