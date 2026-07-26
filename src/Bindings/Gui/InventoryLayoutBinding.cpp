#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventoryLayoutBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/InventoryBinding.h"
#include "Bindings/Gui/InventoryGUIBinding.h"
#include "Bindings/InventorySectionBinding.h"
#include "Bindings/Gui/InventorySectionGUIBinding.h"

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

static int InventoryLayout_get_dataPanelInfos(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    return pushObject<GameDataCopyStandalone>(L, &instance->dataPanelInfos, GameDataCopyStandaloneBinding::getMetatableName());
}

static int InventoryLayout_get_window(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    lua_pushlightuserdata(L, (void*)instance->window);
    return 1;
}

// --- Setters for InventoryLayout ---
static int InventoryLayout_set_datapanel(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    instance->datapanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

static int InventoryLayout_set_dataPanelInfos(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    instance->dataPanelInfos = *checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    return 0;
}

int InventoryLayoutBinding::_CONSTRUCTOR(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    const std::string file = luaL_checkstring(L, 2);
    InventoryLayout* result = instance->_CONSTRUCTOR(file);
    return pushObject<InventoryLayout>(L, result, InventoryLayoutBinding::getMetatableName());
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

    const std::string name = luaL_checkstring(L, 2);
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

    const std::string name = luaL_checkstring(L, 2);
    instance->setupDataPanelInfos(name);
    return 0;
}

int InventoryLayoutBinding::createSectionGUI(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    InventorySectionGUI* result = instance->createSectionGUI(section);
    return pushObject<InventorySectionGUI>(L, result, InventorySectionGUIBinding::getMetatableName());
}

int InventoryLayoutBinding::setSectionGUIDisabled(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    const std::string sectionName = luaL_checkstring(L, 2);
    int width = (int)luaL_checkinteger(L, 3);
    int height = (int)luaL_checkinteger(L, 4);
    instance->setSectionGUIDisabled(sectionName, width, height);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 239: void setupSections(...) - unsupported arg type
  line 246: void notifyCellSizeChanged(...) - static method
  line 251: MyGUI::types::TSize<int> resizeSection(...) - unsupported return type
  line 252: MyGUI::types::TSize<int> resizeSectionWidget(...) - unsupported return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - InventoryLayout_get_window: MyGUI::Window* (unbound pointer)
  - InventoryLayoutBinding::getWindow: MyGUI::Window* (unbound pointer)
  - InventoryLayoutBinding::getWidget: MyGUI::Widget* (unbound pointer)
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
        { "createSectionGUI", InventoryLayoutBinding::createSectionGUI },
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
    registerGetter(L, "datapanel", InventoryLayout_get_datapanel);
    registerGetter(L, "dataPanelInfos", InventoryLayout_get_dataPanelInfos);
    registerGetter(L, "window", InventoryLayout_get_window);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "datapanel", InventoryLayout_set_datapanel);
    registerSetter(L, "dataPanelInfos", InventoryLayout_set_dataPanelInfos);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    setMetatableParent(L, InventoryLayoutBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua