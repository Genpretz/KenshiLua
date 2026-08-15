#include "pch.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLine_ResearchBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DataPanelLineBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

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

int DataPanelLine_ResearchBinding::createMe(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->createMe(parent, top, lastLine);
    return 0;
}

int DataPanelLine_ResearchBinding::_NV_createMe(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    DatapanelGUI* parent = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    float top = (float)luaL_checknumber(L, 3);
    bool lastLine = lua_toboolean(L, 4) != 0;
    instance->_NV_createMe(parent, top, lastLine);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 121: void setToolTipMainBar(...) - overloaded method
  line 122: void _NV_setToolTipMainBar(...) - overloaded method
  line 123: void setToolTipMainBar(...) - overloaded method
  line 124: void _NV_setToolTipMainBar(...) - overloaded method
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
        { "createMe", DataPanelLine_ResearchBinding::createMe },
        { "_NV_createMe", DataPanelLine_ResearchBinding::_NV_createMe },
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
    registerGetter(L, "v1", DataPanelLine_Research_get_v1);
    registerGetter(L, "v2", DataPanelLine_Research_get_v2);
    registerGetter(L, "hasXBut", DataPanelLine_Research_get_hasXBut);
    registerGetter(L, "barSkin", DataPanelLine_Research_get_barSkin);
    registerGetter(L, "bar", DataPanelLine_Research_get_bar);
    registerGetter(L, "but", DataPanelLine_Research_get_but);
    registerGetter(L, "Xbut", DataPanelLine_Research_get_Xbut);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "v1", DataPanelLine_Research_set_v1);
    registerSetter(L, "v2", DataPanelLine_Research_set_v2);
    registerSetter(L, "hasXBut", DataPanelLine_Research_set_hasXBut);
    registerSetter(L, "barSkin", DataPanelLine_Research_set_barSkin);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to DataPanelLine
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, DataPanelLine_ResearchBinding::getMetatableName(), DataPanelLineBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua