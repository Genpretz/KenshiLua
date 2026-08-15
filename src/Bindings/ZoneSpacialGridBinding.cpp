#include "pch.h"
#include "kenshi\ZoneManager.h"
#include "ZoneSpacialGridBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/ZoneMapBinding.h"
#include <kenshi/ZoneManager.h>

namespace KenshiLua
{

static ZoneSpacialGrid* getInstance(lua_State* L, int idx)
{
    return checkObject<ZoneSpacialGrid>(L, idx, ZoneSpacialGridBinding::getMetatableName());
}

// --- Getters for ZoneSpacialGrid ---
static int ZoneSpacialGrid_get_zones(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    lua_pushlightuserdata(L, (void*)instance->zones);
    return 1;
}

static int ZoneSpacialGrid_get_createCellsFunc(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    lua_pushlightuserdata(L, (void*)instance->createCellsFunc);
    return 1;
}

static int ZoneSpacialGrid_get_cellCount(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    lua_pushinteger(L, instance->cellCount);
    return 1;
}

static int ZoneSpacialGrid_get_cellSize(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    lua_pushnumber(L, instance->cellSize);
    return 1;
}

static int ZoneSpacialGrid_get_mutex(lua_State* L) { return 0; }

// --- Setters for ZoneSpacialGrid ---
static int ZoneSpacialGrid_set_cellCount(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    instance->cellCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int ZoneSpacialGrid_set_cellSize(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");
    instance->cellSize = (float)luaL_checknumber(L, 2);
    return 0;
}

static int ZoneSpacialGrid_set_mutex(lua_State* L) { return 0; }

int ZoneSpacialGridBinding::add(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    RootObject* o = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    unsigned int result = instance->add(o);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneSpacialGridBinding::remove(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    RootObject* o = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = instance->remove(o);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ZoneSpacialGridBinding::update(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    RootObject* o = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    ZoneSpacialGrid::Result result = instance->update(o);
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int ZoneSpacialGridBinding::addZone(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    ZoneMap* z = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->addZone(z);
    return 0;
}

int ZoneSpacialGridBinding::removeZone(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    ZoneMap* z = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    instance->removeZone(z);
    return 0;
}

int ZoneSpacialGridBinding::getZoneKey(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    unsigned int result = instance->getZoneKey(p);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneSpacialGridBinding::getCellKey(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    ZoneMap* zone = checkObject<ZoneMap>(L, 2, ZoneMapBinding::getMetatableName());
    Ogre::Vector3 p;
    readVector3(L, 3, p);
    unsigned int result = instance->getCellKey(zone, p);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneSpacialGridBinding::getFullKey(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    unsigned int result = instance->getFullKey(p);
    lua_pushinteger(L, result);
    return 1;
}

int ZoneSpacialGridBinding::initialiseGrid(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    float size = (float)luaL_checknumber(L, 2);
    instance->initialiseGrid(size);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 109: int getObjects(...) - overloaded method
  line 110: int getObjects(...) - overloaded method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - ZoneSpacialGrid_get_zones: ZoneSpacialGrid::ZoneCell** (unbound pointer)
  - ZoneSpacialGrid_get_createCellsFunc: function* (unbound pointer)
*/

int ZoneSpacialGridBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ZoneSpacialGridBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ZoneSpacialGrid object");
    return 1;
}

void ZoneSpacialGridBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ZoneSpacialGridBinding::gc },
        { "__tostring", ZoneSpacialGridBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "add", ZoneSpacialGridBinding::add },
        { "remove", ZoneSpacialGridBinding::remove },
        { "update", ZoneSpacialGridBinding::update },
        { "addZone", ZoneSpacialGridBinding::addZone },
        { "removeZone", ZoneSpacialGridBinding::removeZone },
        { "getZoneKey", ZoneSpacialGridBinding::getZoneKey },
        { "getCellKey", ZoneSpacialGridBinding::getCellKey },
        { "getFullKey", ZoneSpacialGridBinding::getFullKey },
        { "initialiseGrid", ZoneSpacialGridBinding::initialiseGrid },
        { 0, 0 }
    };

    registerClass(
        L, 
        ZoneSpacialGridBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ZoneSpacialGridBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "zones", ZoneSpacialGrid_get_zones);
    registerGetter(L, "createCellsFunc", ZoneSpacialGrid_get_createCellsFunc);
    registerGetter(L, "cellCount", ZoneSpacialGrid_get_cellCount);
    registerGetter(L, "cellSize", ZoneSpacialGrid_get_cellSize);
    registerGetter(L, "mutex", ZoneSpacialGrid_get_mutex);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "cellCount", ZoneSpacialGrid_set_cellCount);
    registerSetter(L, "cellSize", ZoneSpacialGrid_set_cellSize);
    registerSetter(L, "mutex", ZoneSpacialGrid_set_mutex);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua