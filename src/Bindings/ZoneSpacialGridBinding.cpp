#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "ZoneSpacialGridBinding.h"
#include "Lua/BindingHelpers.h"

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


int ZoneSpacialGridBinding::_CONSTRUCTOR(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    ZoneSpacialGrid* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ZoneSpacialGridBinding::_DESTRUCTOR(lua_State* L)
{
    ZoneSpacialGrid* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ZoneSpacialGrid is nil");

    instance->_DESTRUCTOR();
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
  line 106: unsigned int add(...) - unsupported arg type
  line 107: bool remove(...) - unsupported arg type
  line 108: ZoneSpacialGrid::Result update(...) - unsupported arg type
  line 109: int getObjects(...) - overloaded method
  line 110: int getObjects(...) - overloaded method
  line 111: void addZone(...) - unsupported arg type
  line 112: void removeZone(...) - unsupported arg type
  line 120: unsigned int getCellKey(...) - unsupported arg type
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
        { "_CONSTRUCTOR", ZoneSpacialGridBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ZoneSpacialGridBinding::_DESTRUCTOR },
        { "getZoneKey", ZoneSpacialGridBinding::getZoneKey },
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
    lua_pushcfunction(L, ZoneSpacialGrid_get_zones);
    lua_setfield(L, -2, "zones");
    lua_pushcfunction(L, ZoneSpacialGrid_get_createCellsFunc);
    lua_setfield(L, -2, "createCellsFunc");
    lua_pushcfunction(L, ZoneSpacialGrid_get_cellCount);
    lua_setfield(L, -2, "cellCount");
    lua_pushcfunction(L, ZoneSpacialGrid_get_cellSize);
    lua_setfield(L, -2, "cellSize");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ZoneSpacialGrid_set_cellCount);
    lua_setfield(L, -2, "cellCount");
    lua_pushcfunction(L, ZoneSpacialGrid_set_cellSize);
    lua_setfield(L, -2, "cellSize");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua