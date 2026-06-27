#include "pch.h"
#include <kenshi/gui/DataPanelLine.h>
#include "DataPanelLine_ResearchBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"

namespace KenshiLua
{

static DataPanelLine_Research* getInstance(lua_State* L, int idx)
{
    return checkObject<DataPanelLine_Research>(L, idx, DataPanelLine_ResearchBinding::getMetatableName());
}

// --- Getters for DataPanelLine_Research ---
static int DataPanelLine_Research_get_v1(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushnumber(L, instance->v1);
    return 1;
}

static int DataPanelLine_Research_get_v2(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushnumber(L, instance->v2);
    return 1;
}

static int DataPanelLine_Research_get_hasXBut(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushboolean(L, instance->hasXBut ? 1 : 0);
    return 1;
}

static int DataPanelLine_Research_get_barSkin(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushstring(L, instance->barSkin.c_str());
    return 1;
}

static int DataPanelLine_Research_get_bar(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushlightuserdata(L, (void*)instance->bar);
    return 1;
}

static int DataPanelLine_Research_get_but(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushlightuserdata(L, (void*)instance->but);
    return 1;
}

static int DataPanelLine_Research_get_Xbut(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    lua_pushlightuserdata(L, (void*)instance->Xbut);
    return 1;
}

// --- Setters for DataPanelLine_Research ---
static int DataPanelLine_Research_set_v1(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    instance->v1 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Research_set_v2(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    instance->v2 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int DataPanelLine_Research_set_hasXBut(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    instance->hasXBut = lua_toboolean(L, 2) != 0;
    return 0;
}

static int DataPanelLine_Research_set_barSkin(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    instance->barSkin = luaL_checkstring(L, 2);
    return 0;
}

static int DataPanelLine_Research_set_bar(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    return luaL_error(L, "Read-only or unsupported setter type for bar");
}

static int DataPanelLine_Research_set_but(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    return luaL_error(L, "Read-only or unsupported setter type for but");
}

static int DataPanelLine_Research_set_Xbut(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    return luaL_error(L, "Read-only or unsupported setter type for Xbut");
}

int DataPanelLine_ResearchBinding::_CONSTRUCTOR(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    std::string a = luaL_checkstring(L, 2);
    std::string b = luaL_checkstring(L, 3);
    int cat = (int)luaL_checkinteger(L, 4);
    float vv1 = (float)luaL_checknumber(L, 5);
    std::string _barColor = luaL_checkstring(L, 6);
    bool _Xbut = lua_toboolean(L, 7) != 0;
    DataPanelLine_Research* result = instance->_CONSTRUCTOR(a, b, cat, vv1, _barColor, _Xbut);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int DataPanelLine_ResearchBinding::_DESTRUCTOR(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 120: void setToolTipMainBar(...) - overloaded method
  line 121: void _NV_setToolTipMainBar(...) - overloaded method
  line 122: void setToolTipMainBar(...) - overloaded method
  line 123: void _NV_setToolTipMainBar(...) - overloaded method
  line 124: void createMe(...) - unsupported arg type
  line 125: void _NV_createMe(...) - unsupported arg type
*/

int DataPanelLine_ResearchBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DataPanelLine_ResearchBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DataPanelLine_Research object");
    return 1;
}

void DataPanelLine_ResearchBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DataPanelLine_ResearchBinding::gc },
        { "__tostring", DataPanelLine_ResearchBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", DataPanelLine_ResearchBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", DataPanelLine_ResearchBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        DataPanelLine_ResearchBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DataPanelLine_ResearchBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, DataPanelLine_Research_get_v1);
    lua_setfield(L, -2, "v1");
    lua_pushcfunction(L, DataPanelLine_Research_get_v2);
    lua_setfield(L, -2, "v2");
    lua_pushcfunction(L, DataPanelLine_Research_get_hasXBut);
    lua_setfield(L, -2, "hasXBut");
    lua_pushcfunction(L, DataPanelLine_Research_get_barSkin);
    lua_setfield(L, -2, "barSkin");
    lua_pushcfunction(L, DataPanelLine_Research_get_bar);
    lua_setfield(L, -2, "bar");
    lua_pushcfunction(L, DataPanelLine_Research_get_but);
    lua_setfield(L, -2, "but");
    lua_pushcfunction(L, DataPanelLine_Research_get_Xbut);
    lua_setfield(L, -2, "Xbut");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, DataPanelLine_Research_set_v1);
    lua_setfield(L, -2, "v1");
    lua_pushcfunction(L, DataPanelLine_Research_set_v2);
    lua_setfield(L, -2, "v2");
    lua_pushcfunction(L, DataPanelLine_Research_set_hasXBut);
    lua_setfield(L, -2, "hasXBut");
    lua_pushcfunction(L, DataPanelLine_Research_set_barSkin);
    lua_setfield(L, -2, "barSkin");
    lua_pushcfunction(L, DataPanelLine_Research_set_bar);
    lua_setfield(L, -2, "bar");
    lua_pushcfunction(L, DataPanelLine_Research_set_but);
    lua_setfield(L, -2, "but");
    lua_pushcfunction(L, DataPanelLine_Research_set_Xbut);
    lua_setfield(L, -2, "Xbut");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    setMetatableParent(L, DataPanelLine_ResearchBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua