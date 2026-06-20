#include "pch.h"
#include "Bindings/BuildingCategoryBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/BuildModeWindow.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static BuildingCategory* getS(lua_State* L, int idx)
{
    return checkObject<BuildingCategory>(L, idx, BuildingCategoryBinding::getMetatableName());
}

int BuildingCategoryBinding::gc(lua_State* L) { return noopGc(L); }

int BuildingCategoryBinding::tostring(lua_State* L)
{
    BuildingCategory* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int BuildingCategoryBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, BuildingCategoryBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    BuildingCategory* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    if (strcmp(key, "name") == 0) { lua_pushstring(L, s->name.c_str()); return 1; }
    // TODO Ogre::vector<BuildModeWindow::BuildingGroup>::type buildingGroups; unsupported __index type from header line 34

    lua_pushnil(L);
    return 1;
}

int BuildingCategoryBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    BuildingCategory* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingCategory is nil");

    if (strcmp(key, "name") == 0) { s->name = luaL_checkstring(L, 3); return 0; }
    // TODO Ogre::vector<BuildModeWindow::BuildingGroup>::type buildingGroups; unsupported __newindex type from header line 34

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int BuildingCategoryBinding::_DESTRUCTOR(lua_State* L)
{
    BuildingCategory* s = getS(L, 1);
    if (!s) return luaL_error(L, "BuildingCategory is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 35: bool operator<(...) - operator
  line 37: BuildingCategory* _CONSTRUCTOR(...) - overloaded method
  line 39: BuildingCategory* _CONSTRUCTOR(...) - overloaded method
  line 42: BuildModeWindow::BuildingCategory& operator=(...) - operator
*/

void BuildingCategoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       BuildingCategoryBinding::gc },
        { "__tostring", BuildingCategoryBinding::tostring },
        { "__index",    BuildingCategoryBinding::index },
        { "__newindex", BuildingCategoryBinding::newindex },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", BuildingCategoryBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, BuildingCategoryBinding::getMetatableName(), meta, methods);
}

} // namespace KenshiLua