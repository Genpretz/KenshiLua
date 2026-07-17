#include "pch.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

#include <kenshi/gui/InventoryGUI.h>
#include "InventoryLayoutBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static InventoryLayout* getInstance(lua_State* L, int idx)
{
    return checkObject<InventoryLayout>(L, idx, InventoryLayoutBinding::getMetatableName());
}

// --- Getters for InventoryLayout ---
static int InventoryLayout_get_datapanel(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    return pushObject<DatapanelGUI>(L, instance->datapanel, DatapanelGUIBinding::getMetatableName());
}

static int InventoryLayout_get_window(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

// --- Setters for InventoryLayout ---
int InventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    std::string file = luaL_checkstring(L, 2);
    InventoryLayout* result = instance->_CONSTRUCTOR(file);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int InventoryLayoutBinding::getWindow(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    MyGUI::Window* result = instance->getWindow();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryLayoutBinding::getWidget(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    MyGUI::Widget* result = instance->getWidget(name);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int InventoryLayoutBinding::getDatapanel(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    DatapanelGUI* result = instance->getDatapanel();
    return pushObject<DatapanelGUI>(L, result, DatapanelGUIBinding::getMetatableName());
}

int InventoryLayoutBinding::_NV_getDatapanel(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    DatapanelGUI* result = instance->_NV_getDatapanel();
    return pushObject<DatapanelGUI>(L, result, DatapanelGUIBinding::getMetatableName());
}

int InventoryLayoutBinding::setupDataPanelInfos(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    std::string name = luaL_checkstring(L, 2);
    instance->setupDataPanelInfos(name);
    return 0;
}

int InventoryLayoutBinding::setSectionGUIDisabled(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    std::string sectionName = luaL_checkstring(L, 2);
    int width = (int)luaL_checkinteger(L, 3);
    int height = (int)luaL_checkinteger(L, 4);
    instance->setSectionGUIDisabled(sectionName, width, height);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 239: void setupSections(...) - unsupported arg type
  line 246: void notifyCellSizeChanged(...) - static method
  line 249: InventorySectionGUI* createSectionGUI(...) - unsupported arg type
  line 251: MyGUI::types::TSize<int> resizeSection(...) - unsupported return type
  line 252: MyGUI::types::TSize<int> resizeSectionWidget(...) - unsupported return type
*/

/*
Skipped properties needing manual binding:
  line 247: dataPanelInfos (GameDataCopyStandalone) - unsupported type
*/

int InventoryLayoutBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int InventoryLayoutBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.InventoryLayout object");
    return 1;
}

void InventoryLayoutBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       InventoryLayoutBinding::gc },
        { "__tostring", InventoryLayoutBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", InventoryLayoutBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", InventoryLayoutBinding::_DESTRUCTOR },
        { "getWindow", InventoryLayoutBinding::getWindow },
        { "getWidget", InventoryLayoutBinding::getWidget },
        { "getDatapanel", InventoryLayoutBinding::getDatapanel },
        { "_NV_getDatapanel", InventoryLayoutBinding::_NV_getDatapanel },
        { "setupDataPanelInfos", InventoryLayoutBinding::setupDataPanelInfos },
        { "setSectionGUIDisabled", InventoryLayoutBinding::setSectionGUIDisabled },
        { 0, 0 }
    };

    registerClass(
        L, 
        InventoryLayoutBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, InventoryLayoutBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, InventoryLayout_get_datapanel);
    lua_setfield(L, -2, "datapanel");
    lua_pushcfunction(L, InventoryLayout_get_window);
    lua_setfield(L, -2, "window");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // // // // // // // // // setMetatableParent(L, InventoryLayoutBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua