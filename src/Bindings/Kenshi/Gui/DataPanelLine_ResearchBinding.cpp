#include "pch.h"
#include "Bindings/MyGUI/MyGuiTypes.h"
#include "kenshi\gui\DataPanelLine.h"
#include "DataPanelLine_ResearchBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/DataPanelLineBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"

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
    return MyGUIBindings::pushWidget(L, instance->bar);
}

static int DataPanelLine_Research_get_but(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    return MyGUIBindings::pushWidget(L, instance->but);
}

static int DataPanelLine_Research_get_Xbut(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");
    return MyGUIBindings::pushWidget(L, instance->Xbut);
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

int DataPanelLine_ResearchBinding::setToolTipMainBar(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    bool updateable = lua_toboolean(L, 3) != 0;
    if (lua_type(L, 2) == LUA_TSTRING)
    {
        std::string s = luaL_checkstring(L, 2);
        instance->setToolTipMainBar(s, updateable);
        return 0;
    }

    lektor<StringPair>* pairs = testObject<lektor<StringPair> >(L, 2, LektorValueBinding<StringPair>::metaName);
    if (!pairs) return luaL_argerror(L, 2, "string or lektor<StringPair> expected");
    instance->setToolTipMainBar(*pairs, updateable);
    return 0;
}

int DataPanelLine_ResearchBinding::_NV_setToolTipMainBar(lua_State* L)
{
    DataPanelLine_Research* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "DataPanelLine_Research is nil");

    bool updateable = lua_toboolean(L, 3) != 0;
    if (lua_type(L, 2) == LUA_TSTRING)
    {
        std::string s = luaL_checkstring(L, 2);
        instance->_NV_setToolTipMainBar(s, updateable);
        return 0;
    }

    lektor<StringPair>* pairs = testObject<lektor<StringPair> >(L, 2, LektorValueBinding<StringPair>::metaName);
    if (!pairs) return luaL_argerror(L, 2, "string or lektor<StringPair> expected");
    instance->_NV_setToolTipMainBar(*pairs, updateable);
    return 0;
}

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
        { "setToolTipMainBar", DataPanelLine_ResearchBinding::setToolTipMainBar },
        { "_NV_setToolTipMainBar", DataPanelLine_ResearchBinding::_NV_setToolTipMainBar },
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