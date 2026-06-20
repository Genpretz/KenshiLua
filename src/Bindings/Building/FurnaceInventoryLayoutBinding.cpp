#include "pch.h"
#include "Bindings/FurnaceInventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/FurnaceBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static FurnaceInventoryLayout* getS(lua_State* L, int idx)
{
    return checkObject<FurnaceInventoryLayout>(L, idx, FurnaceInventoryLayoutBinding::getMetatableName());
}

int FurnaceInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

int FurnaceInventoryLayoutBinding::tostring(lua_State* L)
{
    FurnaceInventoryLayout* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int FurnaceInventoryLayoutBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, FurnaceInventoryLayoutBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    FurnaceInventoryLayout* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }


    lua_pushnil(L);
    return 1;
}

int FurnaceInventoryLayoutBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    FurnaceInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceInventoryLayout is nil");


    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int FurnaceInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    FurnaceInventoryLayout* s = getS(L, 1);
    if (!s) return luaL_error(L, "FurnaceInventoryLayout is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 12: FurnaceInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
  line 13: void setupSections(...) - unsupported arg type
  line 14: void _NV_setupSections(...) - unsupported arg type
*/

void FurnaceInventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FurnaceInventoryLayoutBinding::gc },
        { "__tostring", FurnaceInventoryLayoutBinding::tostring },
        { "__index",    FurnaceInventoryLayoutBinding::index },
        { "__newindex", FurnaceInventoryLayoutBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FurnaceInventoryLayoutBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, FurnaceInventoryLayoutBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua