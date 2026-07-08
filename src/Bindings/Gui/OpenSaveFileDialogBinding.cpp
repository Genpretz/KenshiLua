#include "pch.h"
#include <kenshi/gui/OpenSaveFileDialog.h>
#include "OpenSaveFileDialogBinding.h"
#include "Lua/BindingHelpers.h"

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
}

static int OpenSaveFileDialog_get_fileNameTxt(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->fileNameTxt);
    return 1;
}

static int OpenSaveFileDialog_get_currentFolderList(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->currentFolderList);
    return 1;
}

static int OpenSaveFileDialog_get_openSaveButton(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");
    lua_pushlightuserdata(L, (void*)instance->openSaveButton);
    return 1;
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

int OpenSaveFileDialogBinding::_DESTRUCTOR(lua_State* L)
{
    OpenSaveFileDialog* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "OpenSaveFileDialog is nil");

    instance->_DESTRUCTOR();
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

/*
Skipped methods needing manual binding:
  line 14: OpenSaveFileDialog* _CONSTRUCTOR(...) - unsupported arg type
  line 21: const std::string& getCurrentFolder(...) - reference return type
  line 23: const std::string& getFileName(...) - reference return type
  line 24: void setRecentFolders(...) - unsupported arg type
  line 26: const std::string& getFileMask(...) - reference return type
  line 28: void notifyDirectoryComboAccept(...) - unsupported arg type
  line 29: void notifyDirectoryComboChangePosition(...) - unsupported arg type
  line 30: void notifyListChangePosition(...) - unsupported arg type
  line 31: void notifyListSelectAccept(...) - unsupported arg type
  line 32: void closeWindow(...) - unsupported arg type
  line 34: void accept(...) - unsupported arg type
  line 35: void cancel(...) - unsupported arg type
  line 36: void upFolder(...) - unsupported arg type
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
        { "_DESTRUCTOR", OpenSaveFileDialogBinding::_DESTRUCTOR },
        { "setVisible", OpenSaveFileDialogBinding::setVisible },
        { "getVisible", OpenSaveFileDialogBinding::getVisible },
        { "setDialogInfo", OpenSaveFileDialogBinding::setDialogInfo },
        { "setCurrentFolder", OpenSaveFileDialogBinding::setCurrentFolder },
        { "setFileName", OpenSaveFileDialogBinding::setFileName },
        { "setFileMask", OpenSaveFileDialogBinding::setFileMask },
        { "update", OpenSaveFileDialogBinding::update },
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
    lua_pushcfunction(L, OpenSaveFileDialog_get_filesList);
    lua_setfield(L, -2, "filesList");
    lua_pushcfunction(L, OpenSaveFileDialog_get_fileNameTxt);
    lua_setfield(L, -2, "fileNameTxt");
    lua_pushcfunction(L, OpenSaveFileDialog_get_currentFolderList);
    lua_setfield(L, -2, "currentFolderList");
    lua_pushcfunction(L, OpenSaveFileDialog_get_openSaveButton);
    lua_setfield(L, -2, "openSaveButton");
    lua_pushcfunction(L, OpenSaveFileDialog_get_currentFolder);
    lua_setfield(L, -2, "currentFolder");
    lua_pushcfunction(L, OpenSaveFileDialog_get_fileName);
    lua_setfield(L, -2, "fileName");
    lua_pushcfunction(L, OpenSaveFileDialog_get_fileMask);
    lua_setfield(L, -2, "fileMask");
    lua_pushcfunction(L, OpenSaveFileDialog_get_currentSelected);
    lua_setfield(L, -2, "currentSelected");
    lua_pushcfunction(L, OpenSaveFileDialog_get_folderMode);
    lua_setfield(L, -2, "folderMode");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, OpenSaveFileDialog_set_currentFolder);
    lua_setfield(L, -2, "currentFolder");
    lua_pushcfunction(L, OpenSaveFileDialog_set_fileName);
    lua_setfield(L, -2, "fileName");
    lua_pushcfunction(L, OpenSaveFileDialog_set_fileMask);
    lua_setfield(L, -2, "fileMask");
    lua_pushcfunction(L, OpenSaveFileDialog_set_currentSelected);
    lua_setfield(L, -2, "currentSelected");
    lua_pushcfunction(L, OpenSaveFileDialog_set_folderMode);
    lua_setfield(L, -2, "folderMode");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to wraps::BaseLayout
    // // // // // // // // // setMetatableParent(L, OpenSaveFileDialogBinding::getMetatableName(), wraps::BaseLayoutBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua