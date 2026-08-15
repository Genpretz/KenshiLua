#include "pch.h"
#include "kenshi\gui\LoadSaveWindow.h"
#include "LoadSaveWindowBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"

namespace KenshiLua
{

static LoadSaveWindow* getInstance(lua_State* L, int idx)
{
    return checkObject<LoadSaveWindow>(L, idx, LoadSaveWindowBinding::getMetatableName());
}

// --- Getters for LoadSaveWindow ---
static int LoadSaveWindow_get_list(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");
    lua_pushlightuserdata(L, (void*)instance->list);
    return 1;
}

static int LoadSaveWindow_get_infoPanel(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");
    return pushObject<DatapanelGUI>(L, instance->infoPanel, DatapanelGUIBinding::getMetatableName());
}

// --- Setters for LoadSaveWindow ---
static int LoadSaveWindow_set_infoPanel(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");
    instance->infoPanel = lua_isnoneornil(L, 2) ? nullptr : checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    return 0;
}

int LoadSaveWindowBinding::select(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->select(index);
    return 0;
}

int LoadSaveWindowBinding::_NV_select(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int index = (int)luaL_checkinteger(L, 2);
    instance->_NV_select(index);
    return 0;
}

int LoadSaveWindowBinding::getWidget(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    MyGUI::Widget* result = instance->getWidget();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int LoadSaveWindowBinding::deleteSelectedSave(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int mbResult = (int)luaL_checkinteger(L, 2);
    instance->deleteSelectedSave(mbResult);
    return 0;
}

int LoadSaveWindowBinding::addOption(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int key = (int)luaL_checkinteger(L, 2);
    const std::string check = luaL_checkstring(L, 3);
    const std::string label = luaL_checkstring(L, 4);
    const std::string caption = luaL_checkstring(L, 5);
    instance->addOption(key, check, label, caption);
    return 0;
}

int LoadSaveWindowBinding::enableOption(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int key = (int)luaL_checkinteger(L, 2);
    bool enabled = lua_toboolean(L, 3) != 0;
    instance->enableOption(key, enabled);
    return 0;
}

int LoadSaveWindowBinding::getOptions(lua_State* L)
{
    LoadSaveWindow* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LoadSaveWindow is nil");

    int result = instance->getOptions();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 18: void close(...) - unsupported arg type
  line 19: void selectGame(...) - unsupported arg type
  line 20: void keyPressed(...) - unsupported arg type
  line 21: void toggleCheck(...) - unsupported arg type
  line 26: void sortListComparer(...) - unsupported arg type
  line 27: void createInfo(...) - unsupported arg type
  line 28: void updateInfo(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - LoadSaveWindow_get_list: MyGUI::MultiListBox* (unbound pointer)
  - LoadSaveWindowBinding::getWidget: MyGUI::Widget* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 30: games (lektor<SaveInfo>) - unsupported type
  line 32: options (lektor<MyGUI::Button*>) - unsupported type
  line 36: savesTimesStr (std::map<MyGUI::UString, int, std::less<MyGUI::UString>, Ogre::STLAllocator<std::pair<MyGUI::UString const, int>, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int LoadSaveWindowBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LoadSaveWindowBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LoadSaveWindow object");
    return 1;
}

void LoadSaveWindowBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LoadSaveWindowBinding::gc },
        { "__tostring", LoadSaveWindowBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "select", LoadSaveWindowBinding::select },
        { "_NV_select", LoadSaveWindowBinding::_NV_select },
        { "getWidget", LoadSaveWindowBinding::getWidget },
        { "deleteSelectedSave", LoadSaveWindowBinding::deleteSelectedSave },
        { "addOption", LoadSaveWindowBinding::addOption },
        { "enableOption", LoadSaveWindowBinding::enableOption },
        { "getOptions", LoadSaveWindowBinding::getOptions },
        { 0, 0 }
    };

    registerClass(
        L, 
        LoadSaveWindowBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LoadSaveWindowBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "list", LoadSaveWindow_get_list);
    registerGetter(L, "infoPanel", LoadSaveWindow_get_infoPanel);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "infoPanel", LoadSaveWindow_set_infoPanel);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, LoadSaveWindowBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua