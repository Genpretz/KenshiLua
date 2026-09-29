#include "pch.h"
#include "kenshi\gui\InventoryGUI.h"
#include "InventoryLayoutBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/InventoryBinding.h"
#include "Bindings/Kenshi/Gui/InventoryGUIBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/Gui/InventorySectionGUIBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/MyGUI/TypesBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"
#include "Bindings/MyGUI/MyGuiTypes.h"

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
    return pushObject<MyGUI::Window>(L, instance->window, WindowBinding::getMetatableName());
}

// --- Setters for InventoryLayout ---
static int InventoryLayout_set_window(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");
    instance->window = lua_isnoneornil(L, 2) ? nullptr : WindowBinding::getWindow(L, 2);
    return 0;
}
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

int InventoryLayoutBinding::getWindow(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    MyGUI::Window* result = instance->getWindow();
    return pushObject<MyGUI::Window>(L, result, WindowBinding::getMetatableName());
}

int InventoryLayoutBinding::getWidget(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    const std::string name = luaL_checkstring(L, 2);
    MyGUI::Widget* result = instance->getWidget(name);
    return MyGUIBindings::pushWidget(L, result);
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

int InventoryLayoutBinding::notifyCellSizeChanged(lua_State* L)
{
    InventoryLayout::notifyCellSizeChanged();
    return 0;
}

int InventoryLayoutBinding::resizeSection(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    InventorySection* section = checkObject<InventorySection>(L, 2, InventorySectionBinding::getMetatableName());
    InventorySectionGUI* sectionGUI = checkObject<InventorySectionGUI>(L, 3, InventorySectionGUIBinding::getMetatableName());
    MyGUI::types::TSize<int> result = instance->resizeSection(section, sectionGUI);
    return pushValue<MyGUI::IntSize>(L, result, IntSizeBinding::getMetatableName());
}

int InventoryLayoutBinding::resizeSectionWidget(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    int width = (int)luaL_checkinteger(L, 2);
    int height = (int)luaL_checkinteger(L, 3);
    MyGUI::Widget* widget = WidgetBinding::getWidget(L, 4);
    MyGUI::types::TSize<int> result = instance->resizeSectionWidget(width, height, widget);
    return pushValue<MyGUI::IntSize>(L, result, IntSizeBinding::getMetatableName());
}

typedef StdMapBinding<std::string, InventorySectionGUI*> InventorySectionsMapBinding;

int InventoryLayoutBinding::setupSections(lua_State* L)
{
    InventoryLayout* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "InventoryLayout is nil");

    InventoryGUI* gui = checkObject<InventoryGUI>(L, 2, InventoryGUIBinding::getMetatableName());
    if (!gui) return luaL_error(L, "Argument 2 to setupSections must be InventoryGUI");
    auto* sections = InventorySectionsMapBinding::get(L, 3);
    if (!sections) return luaL_error(L, "Argument 3 to setupSections must be std::map<std::string, InventorySectionGUI*>");
    Inventory* inv = checkObject<Inventory>(L, 4, InventoryBinding::getMetatableName());
    if (!inv) return luaL_error(L, "Argument 4 to setupSections must be Inventory");

    instance->setupSections(gui, *sections, inv);
    return 0;
}

/*
CellSize bindings intentionally disabled.
InventoryLayout::CellSize is static storage whose address is not exposed as a
linkable symbol. The known GOG RVA must not be used for the unverified Steam
build. Re-enable these bindings only after a version-independent accessor or
verified per-build address is available.
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
        { "getWindow", InventoryLayoutBinding::getWindow },
        { "getWidget", InventoryLayoutBinding::getWidget },
        { "getDatapanel", InventoryLayoutBinding::getDatapanel },
        { "_NV_getDatapanel", InventoryLayoutBinding::_NV_getDatapanel },
        { "setupDataPanelInfos", InventoryLayoutBinding::setupDataPanelInfos },
        { "createSectionGUI", InventoryLayoutBinding::createSectionGUI },
        { "setSectionGUIDisabled", InventoryLayoutBinding::setSectionGUIDisabled },
        { "notifyCellSizeChanged", InventoryLayoutBinding::notifyCellSizeChanged },
        { "resizeSection", InventoryLayoutBinding::resizeSection },
        { "resizeSectionWidget", InventoryLayoutBinding::resizeSectionWidget },
        { "setupSections", InventoryLayoutBinding::setupSections },
        // CellSize intentionally omitted; see the note above.
        { 0, 0 }
    };

    InventorySectionsMapBinding::registerBinding(L, "std::map<std::string, InventorySectionGUI*>", nullptr, InventorySectionGUIBinding::getMetatableName());

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
    registerSetter(L, "window", InventoryLayout_set_window);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, InventoryLayoutBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack

    // Register global class table for static methods
    pushGlobalTable(L, "InventoryLayout");
    registerStaticMethod(L, "notifyCellSizeChanged", InventoryLayoutBinding::notifyCellSizeChanged);
    // CellSize intentionally omitted; see the note above.
    lua_setglobal(L, "InventoryLayout");
}

} // namespace KenshiLua