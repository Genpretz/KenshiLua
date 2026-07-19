#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_FactionBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_Faction* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Faction>(L, idx, DataPanelLine_FactionBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Faction ---
static int DataPanelLine_Faction_get_v1(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    lua_pushnumber(L, instance->v1);
    return 1;
}

static int DataPanelLine_Faction_get_v2(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    lua_pushnumber(L, instance->v2);
    return 1;
}

static int DataPanelLine_Faction_get_bar(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    lua_pushlightuserdata(L, (void*)instance->bar);
    return 1;
}

static int DataPanelLine_Faction_get_bar2(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    lua_pushlightuserdata(L, (void*)instance->bar2);
    return 1;
}

static int DataPanelLine_Faction_get_but(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    lua_pushlightuserdata(L, (void*)instance->but);
    return 1;
}

// --- Setters for DataPanelLine_Faction ---
static int DataPanelLine_Faction_set_v1(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    instance->v1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Faction_set_v2(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    instance->v2 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Faction_set_bar(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bar");
}

static int DataPanelLine_Faction_set_bar2(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bar2");
}

static int DataPanelLine_Faction_set_but(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");
    return luaL_error(L, "Read-only or unsupported setter type for but");
}

int DataPanelLine_FactionBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");

    std::string a = luaL_checkstring(L, 2);
    std::string b = luaL_checkstring(L, 3);
    int cat = (int)luaL_checkinteger(L, 4);
    float vv1 = (float)luaL_checknumber(L, 5);
    float vv2 = (float)luaL_checknumber(L, 6);
    DataPanelLine_Faction* result = instance->_CONSTRUCTOR(a, b, cat, vv1, vv2);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_FactionBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Faction* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Faction is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 97: void createMe(...) - unsupported arg type
  line 98: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_FactionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_FactionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Faction object");
    return 1;
}

void DataPanelLine_FactionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_FactionBinding::gc },
        { "__tostring", DataPanelLine_FactionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DataPanelLine_FactionBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DataPanelLine_FactionBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_FactionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_FactionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Faction_get_v1);
    lua_setfield(L, -2, "v1");
    lua_pushcfunction(L, DataPanelLine_Faction_get_v2);
    lua_setfield(L, -2, "v2");
    lua_pushcfunction(L, DataPanelLine_Faction_get_bar);
    lua_setfield(L, -2, "bar");
    lua_pushcfunction(L, DataPanelLine_Faction_get_bar2);
    lua_setfield(L, -2, "bar2");
    lua_pushcfunction(L, DataPanelLine_Faction_get_but);
    lua_setfield(L, -2, "but");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Faction_set_v1);
    lua_setfield(L, -2, "v1");
    lua_pushcfunction(L, DataPanelLine_Faction_set_v2);
    lua_setfield(L, -2, "v2");
    lua_pushcfunction(L, DataPanelLine_Faction_set_bar);
    lua_setfield(L, -2, "bar");
    lua_pushcfunction(L, DataPanelLine_Faction_set_bar2);
    lua_setfield(L, -2, "bar2");
    lua_pushcfunction(L, DataPanelLine_Faction_set_but);
    lua_setfield(L, -2, "but");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // setMetatableParent(L, DataPanelLine_FactionBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
