#include "pch.h"
#include "Bindings/Building/FarmBatchBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/Building/FarmBuilding.h>

#include <cstring>
#include <cstdio>

namespace KenshiLua
{

static FarmBatch* getS(lua_State* L, int idx)
{
    return checkObject<FarmBatch>(L, idx, FarmBatchBinding::getMetatableName());
}

int FarmBatchBinding::gc(lua_State* L) { return noopGc(L); }

int FarmBatchBinding::tostring(lua_State* L)
{
    FarmBatch* s = getS(L, 1);
    return genericTostringPtr(L, "%s", s);
}

int FarmBatchBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, FarmBatchBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    FarmBatch* s = getS(L, 1);
    if (!s) { lua_pushnil(L); return 1; }

    // TODO lektor<FarmBuilding::PlantSource*> plantSource; unsupported __index type from header line 106
    // TODO lektor<int> plantGroups; unsupported __index type from header line 107
    // TODO Ogre::SharedPtr<Ogre::Mesh> geometry; unsupported __index type from header line 108
    if (strcmp(key, "height") == 0) { lua_pushnumber(L, s->height); return 1; }
    if (strcmp(key, "size") == 0) { lua_pushinteger(L, s->size); return 1; }
    if (strcmp(key, "meshesLoaded") == 0) { lua_pushinteger(L, s->meshesLoaded); return 1; }
    // TODO lektor<FarmBuilding*> farms; unsupported __index type from header line 112

    lua_pushnil(L);
    return 1;
}

int FarmBatchBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    FarmBatch* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBatch is nil");

    // TODO lektor<FarmBuilding::PlantSource*> plantSource; unsupported __newindex type from header line 106
    // TODO lektor<int> plantGroups; unsupported __newindex type from header line 107
    // TODO Ogre::SharedPtr<Ogre::Mesh> geometry; unsupported __newindex type from header line 108
    if (strcmp(key, "height") == 0) { s->height = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "size") == 0) { s->size = (int)luaL_checkinteger(L, 3); return 0; }
    if (strcmp(key, "meshesLoaded") == 0) { s->meshesLoaded = (int)luaL_checkinteger(L, 3); return 0; }
    // TODO lektor<FarmBuilding*> farms; unsupported __newindex type from header line 112

    return luaL_error(L, "unknown or read-only field '%s'", key);
}

int FarmBatchBinding::load(lua_State* L)
{
    FarmBatch* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBatch is nil");

    s->load();
    return 0;
}

int FarmBatchBinding::createGeometry(lua_State* L)
{
    FarmBatch* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBatch is nil");

    s->createGeometry();
    return 0;
}

int FarmBatchBinding::_DESTRUCTOR(lua_State* L)
{
    FarmBatch* s = getS(L, 1);
    if (!s) return luaL_error(L, "FarmBatch is nil");

    s->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 102: FarmBatch* _CONSTRUCTOR(...) - unsupported return type
  line 104: void meshLoaded(...) - unsupported arg type
*/

void FarmBatchBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FarmBatchBinding::gc },
        { "__tostring", FarmBatchBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "load", FarmBatchBinding::load },
        { "createGeometry", FarmBatchBinding::createGeometry },
        { "_DESTRUCTOR", FarmBatchBinding::_DESTRUCTOR },
        { 0, 0 }
    };
    registerClass(L, FarmBatchBinding::getMetatableName(), meta, methods, FarmBatchBinding::index, FarmBatchBinding::newindex);
}

} // namespace KenshiLua