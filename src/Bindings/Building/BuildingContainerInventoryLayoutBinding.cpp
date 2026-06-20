#include "pch.h"
#include "Bindings/BuildingContainerInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/StorageBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static BuildingContainerInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<BuildingContainerInventoryLayout>(L, idx, BuildingContainerInventoryLayoutBinding::getMetatableName());
}

int BuildingContainerInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int BuildingContainerInventoryLayoutBinding::tostring(lua_State* L)
{
    BuildingContainerInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int BuildingContainerInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildingContainerInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BuildingContainerInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "capacityText") == 0) { lua_pushinteger(L, (lua_Integer)s->capacityText); return 1; }

    lua_pushnil(L);
    return 1;
}

int BuildingContainerInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BuildingContainerInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    // TODO MyGUI::EditBox* capacityText; unsupported __newindex type from header line 19

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildingContainerInventoryLayoutBinding::setCapacity(lua_State* L)
{
    BuildingContainerInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    int value = (int)luaL_checkinteger(L, 2);
    bool full = lua_toboolean(L, 3) != 0;
    s->setCapacity(value, full);
    return 0;
}

int BuildingContainerInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingContainerInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingContainerInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 15: BuildingContainerInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
  line 16: void setupSections(...) - unsupported arg type
  line 17: void _NV_setupSections(...) - unsupported arg type
*/

void BuildingContainerInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingContainerInventoryLayoutBinding::gc },
        { "__tostring", BuildingContainerInventoryLayoutBinding::tostring },
        { "__index",    BuildingContainerInventoryLayoutBinding::index },
        { "__newindex", BuildingContainerInventoryLayoutBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "setCapacity", BuildingContainerInventoryLayoutBinding::setCapacity },
        { "_DESTRUCTOR", BuildingContainerInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, BuildingContainerInventoryLayoutBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua