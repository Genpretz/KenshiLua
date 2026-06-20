#include "pch.h"
#include "Bindings/BuildingGroupBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/BuildModeWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static BuildingGroup* getS(lua_State* L, int idx)
{
    return checkObject<BuildingGroup>(L, idx, BuildingGroupBinding::getMetatableName());
}

int BuildingGroupBinding::gc(lua_State* L) { return noopGc(L); }

int BuildingGroupBinding::tostring(lua_State* L)
{
    BuildingGroup* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int BuildingGroupBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildingGroupBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BuildingGroup* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
    // TODO Ogre::vector<GameData*>::type buildings; unsupported __index type from header line 19

    lua_pushnil(L);
    return 1;
}

int BuildingGroupBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BuildingGroup* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingGroup is nil");

    if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }
    // TODO Ogre::vector<GameData*>::type buildings; unsupported __newindex type from header line 19

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildingGroupBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingGroup* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingGroup is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: bool operator<(...) - operator
  line 22: BuildingGroup* _CONSTRUCTOR(...) - overloaded method
  line 24: BuildingGroup* _CONSTRUCTOR(...) - overloaded method
  line 27: BuildModeWindow::BuildingGroup& operator=(...) - operator
*/

void BuildingGroupBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingGroupBinding::gc },
        { "__tostring", BuildingGroupBinding::tostring },
        { "__index",    BuildingGroupBinding::index },
        { "__newindex", BuildingGroupBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", BuildingGroupBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, BuildingGroupBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua