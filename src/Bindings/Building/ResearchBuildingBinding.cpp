#include "pch.h"
#include "Bindings/ResearchBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/ResearchBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static ResearchBuilding* getS(lua_State* L, int idx)
{
    return checkObject<ResearchBuilding>(L, idx, ResearchBuildingBinding::getMetatableName());
}

int ResearchBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int ResearchBuildingBinding::tostring(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int ResearchBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, ResearchBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    ResearchBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int ResearchBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int ResearchBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

int ResearchBuildingBinding::dontNeedWorkRightNow(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    bool result = s->dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBuildingBinding::_NV_dontNeedWorkRightNow(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    bool result = s->_NV_dontNeedWorkRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResearchBuildingBinding::update(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    s->update();
    return 0;
}

int ResearchBuildingBinding::_NV_update(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    s->_NV_update();
    return 0;
}

int ResearchBuildingBinding::notifyConstructionComplete(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    s->notifyConstructionComplete();
    return 0;
}

int ResearchBuildingBinding::_NV_notifyConstructionComplete(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    s->_NV_notifyConstructionComplete();
    return 0;
}

int ResearchBuildingBinding::getTechLevel(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    int result = s->getTechLevel();
    lua_pushinteger(L, result);
    return 1;
}

int ResearchBuildingBinding::_NV_getTechLevel(lua_State* L)
{
    ResearchBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "ResearchBuilding is nil");

    int result = s->_NV_getTechLevel();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 31: ResearchBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 36: TaskType getDefaultTask(...) - unsupported return type
  line 37: TaskType _NV_getDefaultTask(...) - unsupported return type
  line 40: void operate(...) - unsupported arg type
  line 41: void _NV_operate(...) - unsupported arg type
  line 44: void getGUIData(...) - unsupported arg type
  line 45: void _NV_getGUIData(...) - unsupported arg type
  line 48: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 49: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 50: void showResearchWindow(...) - pointer arg
*/

void ResearchBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResearchBuildingBinding::gc },
        { "__tostring", ResearchBuildingBinding::tostring },
        { "__index",    ResearchBuildingBinding::index },
        { "__newindex", ResearchBuildingBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", ResearchBuildingBinding::_DESTRUCTOR },
        { "dontNeedWorkRightNow", ResearchBuildingBinding::dontNeedWorkRightNow },
        { "_NV_dontNeedWorkRightNow", ResearchBuildingBinding::_NV_dontNeedWorkRightNow },
        { "update", ResearchBuildingBinding::update },
        { "_NV_update", ResearchBuildingBinding::_NV_update },
        { "notifyConstructionComplete", ResearchBuildingBinding::notifyConstructionComplete },
        { "_NV_notifyConstructionComplete", ResearchBuildingBinding::_NV_notifyConstructionComplete },
        { "getTechLevel", ResearchBuildingBinding::getTechLevel },
        { "_NV_getTechLevel", ResearchBuildingBinding::_NV_getTechLevel },
        { 0, 0 }
    };
    registerClass(L, ResearchBuildingBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua