#include "pch.h"
#include <kenshi/gui/OpenSaveFileDialog.h>
#include "OpenSaveFileDialogBinding.h"
#include "BaseLayoutBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/MyGUI/MyGUIBinding.h"
#include "Bindings/MyGUI/WidgetBinding.h"
#include "Bindings/MyGUI/ComboBoxBinding.h"
#include "Bindings/MyGUI/ListBoxBinding.h"
#include "Bindings/MyGUI/WindowBinding.h"

namespace KenshiLua
{

static OpenSaveFileDialog* getInstance(lua_State* L, int idx)
{
    return checkObject<OpenSaveFileDialog>(L, idx, OpenSaveFileDialogBinding::getMetatableName());
}

// --- Getters for OpenSaveFileDialog ---
static int OpenSaveFileDialog_get_filesList(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->filesList);
    return 1;
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->filesList, MyGUIBinding::getMetatableName());
}

static int OpenSaveFileDialog_get_fileNameTxt(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->fileNameTxt);
    return 1;
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->fileNameTxt, MyGUIBinding::getMetatableName());
}

static int OpenSaveFileDialog_get_currentFolderList(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->currentFolderList);
    return 1;
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->currentFolderList, MyGUIBinding::getMetatableName());
}

static int OpenSaveFileDialog_get_openSaveButton(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->openSaveButton);
    return 1;
    return pushObject<MyGUI::Widget>(L, (MyGUI::Widget*)instance->openSaveButton, MyGUIBinding::getMetatableName());
}

static int OpenSaveFileDialog_get_currentFolder(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushstring(L, instance->currentFolder.c_str());
    return 1;
}

static int OpenSaveFileDialog_get_fileName(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushstring(L, instance->fileName.c_str());
    return 1;
}

static int OpenSaveFileDialog_get_fileMask(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushstring(L, instance->fileMask.c_str());
    return 1;
}

static int OpenSaveFileDialog_get_currentSelected(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushstring(L, instance->currentSelected.c_str());
    return 1;
}

static int OpenSaveFileDialog_get_folderMode(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushboolean(L, instance->folderMode ? 1 : 0);
    return 1;
}

// --- Setters for OpenSaveFileDialog ---
static int OpenSaveFileDialog_set_currentFolder(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    instance->currentFolder = luaL_checkstring(L, 2);
    return 0;
}

static int OpenSaveFileDialog_set_fileName(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    instance->fileName = luaL_checkstring(L, 2);
    return 0;
}

static int OpenSaveFileDialog_set_fileMask(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    instance->fileMask = luaL_checkstring(L, 2);
    return 0;
}

static int OpenSaveFileDialog_set_currentSelected(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    instance->currentSelected = luaL_checkstring(L, 2);
    return 0;
}

static int OpenSaveFileDialog_set_folderMode(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    instance->folderMode = lua_toboolean(L, 2) != 0;
    return 0;
}

int OpenSaveFileDialogBinding::setVisible(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    bool visible = lua_toboolean(L, 2) != 0;
    instance->setVisible(visible);
    return 0;
}

int OpenSaveFileDialogBinding::getVisible(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    bool result = instance->getVisible();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int OpenSaveFileDialogBinding::setDialogInfo(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    std::string _caption = luaL_checkstring(L, 2);
    std::string _button = luaL_checkstring(L, 3);
    bool _folderMode = lua_toboolean(L, 4) != 0;
    instance->setDialogInfo(_caption, _button, _folderMode);
    return 0;
}

int OpenSaveFileDialogBinding::setCurrentFolder(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    std::string _folder = luaL_checkstring(L, 2);
    instance->setCurrentFolder(_folder);
    return 0;
}

int OpenSaveFileDialogBinding::setFileName(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    std::string _value = luaL_checkstring(L, 2);
    instance->setFileName(_value);
    return 0;
}

int OpenSaveFileDialogBinding::setFileMask(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    std::string _value = luaL_checkstring(L, 2);
    instance->setFileMask(_value);
    return 0;
}

int OpenSaveFileDialogBinding::update(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    instance->update();
    return 0;
}

int OpenSaveFileDialogBinding::getCurrentFolder(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    const std::string& res = instance->getCurrentFolder();
    lua_pushlstring(L, res.data(), res.size());
    return 1;
}

int OpenSaveFileDialogBinding::getFileName(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    const std::string& res = instance->getFileName();
    lua_pushlstring(L, res.data(), res.size());
    return 1;
}

int OpenSaveFileDialogBinding::getFileMask(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    const std::string& res = instance->getFileMask();
    lua_pushlstring(L, res.data(), res.size());
    return 1;
}

int OpenSaveFileDialogBinding::accept(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::Widget* a1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, WidgetBinding::getMetatableName());
    instance->accept(a1);
    return 0;
}

int OpenSaveFileDialogBinding::cancel(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::Widget* a1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, WidgetBinding::getMetatableName());
    instance->cancel(a1);
    return 0;
}

int OpenSaveFileDialogBinding::upFolder(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::Widget* a1 = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Widget>(L, 2, WidgetBinding::getMetatableName());
    instance->upFolder(a1);
    return 0;
}

int OpenSaveFileDialogBinding::notifyDirectoryComboAccept(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::ComboBox* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ComboBox>(L, 2, ComboBoxBinding::getMetatableName());
    unsigned __int64 index = static_cast<unsigned __int64>(luaL_checkinteger(L, 3));
    instance->notifyDirectoryComboAccept(sender, index);
    return 0;
}

int OpenSaveFileDialogBinding::notifyDirectoryComboChangePosition(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::ComboBox* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ComboBox>(L, 2, ComboBoxBinding::getMetatableName());
    unsigned __int64 index = static_cast<unsigned __int64>(luaL_checkinteger(L, 3));
    instance->notifyDirectoryComboChangePosition(sender, index);
    return 0;
}

int OpenSaveFileDialogBinding::notifyListChangePosition(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::ListBox* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = static_cast<unsigned __int64>(luaL_checkinteger(L, 3));
    instance->notifyListChangePosition(sender, index);
    return 0;
}

int OpenSaveFileDialogBinding::notifyListSelectAccept(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::ListBox* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::ListBox>(L, 2, ListBoxBinding::getMetatableName());
    unsigned __int64 index = static_cast<unsigned __int64>(luaL_checkinteger(L, 3));
    instance->notifyListSelectAccept(sender, index);
    return 0;
}

int OpenSaveFileDialogBinding::closeWindow(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    MyGUI::Window* sender = lua_isnoneornil(L, 2) ? nullptr : checkObject<MyGUI::Window>(L, 2, WindowBinding::getMetatableName());
    std::string name = luaL_checkstring(L, 3);
    instance->closeWindow(sender, name);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 24: void setRecentFolders(...) - unsupported arg type
*/

int OpenSaveFileDialogBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int OpenSaveFileDialogBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.OpenSaveFileDialog object");
    return 1;
}

void OpenSaveFileDialogBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       OpenSaveFileDialogBinding::gc },
        { "__tostring", OpenSaveFileDialogBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setVisible", OpenSaveFileDialogBinding::setVisible },
        { "getVisible", OpenSaveFileDialogBinding::getVisible },
        { "setDialogInfo", OpenSaveFileDialogBinding::setDialogInfo },
        { "setCurrentFolder", OpenSaveFileDialogBinding::setCurrentFolder },
        { "getCurrentFolder", OpenSaveFileDialogBinding::getCurrentFolder },
        { "setFileName", OpenSaveFileDialogBinding::setFileName },
        { "getFileName", OpenSaveFileDialogBinding::getFileName },
        { "setFileMask", OpenSaveFileDialogBinding::setFileMask },
        { "getFileMask", OpenSaveFileDialogBinding::getFileMask },
        { "update", OpenSaveFileDialogBinding::update },
        { "accept", OpenSaveFileDialogBinding::accept },
        { "cancel", OpenSaveFileDialogBinding::cancel },
        { "upFolder", OpenSaveFileDialogBinding::upFolder },
        { "notifyDirectoryComboAccept", OpenSaveFileDialogBinding::notifyDirectoryComboAccept },
        { "notifyDirectoryComboChangePosition", OpenSaveFileDialogBinding::notifyDirectoryComboChangePosition },
        { "notifyListChangePosition", OpenSaveFileDialogBinding::notifyListChangePosition },
        { "notifyListSelectAccept", OpenSaveFileDialogBinding::notifyListSelectAccept },
        { "closeWindow", OpenSaveFileDialogBinding::closeWindow },
        { 0, 0 }
    };

    registerClass(
        L, 
        OpenSaveFileDialogBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, OpenSaveFileDialogBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "filesList", OpenSaveFileDialog_get_filesList);
    registerGetter(L, "fileNameTxt", OpenSaveFileDialog_get_fileNameTxt);
    registerGetter(L, "currentFolderList", OpenSaveFileDialog_get_currentFolderList);
    registerGetter(L, "openSaveButton", OpenSaveFileDialog_get_openSaveButton);
    registerGetter(L, "currentFolder", OpenSaveFileDialog_get_currentFolder);
    registerGetter(L, "fileName", OpenSaveFileDialog_get_fileName);
    registerGetter(L, "fileMask", OpenSaveFileDialog_get_fileMask);
    registerGetter(L, "currentSelected", OpenSaveFileDialog_get_currentSelected);
    registerGetter(L, "folderMode", OpenSaveFileDialog_get_folderMode);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "currentFolder", OpenSaveFileDialog_set_currentFolder);
    registerSetter(L, "fileName", OpenSaveFileDialog_set_fileName);
    registerSetter(L, "fileMask", OpenSaveFileDialog_set_fileMask);
    registerSetter(L, "currentSelected", OpenSaveFileDialog_set_currentSelected);
    registerSetter(L, "folderMode", OpenSaveFileDialog_set_folderMode);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, OpenSaveFileDialogBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua