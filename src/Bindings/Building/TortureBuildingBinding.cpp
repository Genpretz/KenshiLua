#include "pch.h"
#include "Bindings/Building/TortureBuildingBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/TortureBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static TortureBuilding* getS(lua_State* L, int idx)
{
    return checkObject<TortureBuilding>(L, idx, TortureBuildingBinding::getMetatableName());
}

int TortureBuildingBinding::gc(lua_State* L) { return noopGc(L); }

int TortureBuildingBinding::tostring(lua_State* L)
{
    TortureBuilding* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int TortureBuildingBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, TortureBuildingBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    TortureBuilding* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "timer") == 0) { lua_pushnumber(L, s->timer); return 1; }

    lua_pushnil(L);
    return 1;
}

int TortureBuildingBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    TortureBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TortureBuilding is nil");

    if (strcmp(key, "timer") == 0) { s->timer = (float)luaL_checknumber(L, 3); return 0; }

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int TortureBuildingBinding::update(lua_State* L)
{
    TortureBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TortureBuilding is nil");

    s->update();
    return 0;
}

int TortureBuildingBinding::_NV_update(lua_State* L)
{
    TortureBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TortureBuilding is nil");

    s->_NV_update();
    return 0;
}

int TortureBuildingBinding::_DESTRUCTOR(lua_State* L)
{
    TortureBuilding* s = getS(L, 1);
    if (!s) return luaL_error(L, "TortureBuilding is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 11: TortureBuilding* _CONSTRUCTOR(...) - unsupported return type
  line 12: StorageBuilding* getFunctionStuff(...) - unsupported return type
  line 13: StorageBuilding* _NV_getFunctionStuff(...) - unsupported return type
*/

void TortureBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TortureBuildingBinding::gc },
        { "__tostring", TortureBuildingBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "update", TortureBuildingBinding::update },
        { "_NV_update", TortureBuildingBinding::_NV_update },
        { "_DESTRUCTOR", TortureBuildingBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, TortureBuildingBinding::getMetatableName(), meta, methods, TortureBuildingBinding::index, TortureBuildingBinding::newindex);
}

} // namespace KenshiLua