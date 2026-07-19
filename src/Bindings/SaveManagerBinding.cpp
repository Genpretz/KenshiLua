#include "pch.h"
#include "kenshi\SaveManager.h"
#include "SaveManagerBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SaveManager* getInstance(lua_State* L, int idx)
{
    return checkObject<SaveManager>(L, idx, SaveManagerBinding::getMetatableName());
}

// --- Getters for SaveManager ---
static int SaveManager_get_currentGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->currentGame.c_str());
    return 1;
}

static int SaveManager_get_saveVersion(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->saveVersion.c_str());
    return 1;
}

static int SaveManager_get_localSavePath(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->localSavePath.c_str());
    return 1;
}

static int SaveManager_get_userSavePath(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->userSavePath.c_str());
    return 1;
}

static int SaveManager_get_signal(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushinteger(L, instance->signal);
    return 1;
}

static int SaveManager_get_flags(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushinteger(L, instance->flags);
    return 1;
}

static int SaveManager_get_delay(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushinteger(L, instance->delay);
    return 1;
}

static int SaveManager_get_name(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->name.c_str());
    return 1;
}

static int SaveManager_get_location(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushstring(L, instance->location.c_str());
    return 1;
}

static int SaveManager_get_loadMenu(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushlightuserdata(L, (void*)instance->loadMenu);
    return 1;
}

static int SaveManager_get_saveMenu(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushlightuserdata(L, (void*)instance->saveMenu);
    return 1;
}

static int SaveManager_get_importMenu(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushlightuserdata(L, (void*)instance->importMenu);
    return 1;
}

static int SaveManager_get_autoSaveTimer(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushnumber(L, instance->autoSaveTimer);
    return 1;
}

static int SaveManager_get_pauseAutoSaveTimer(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    lua_pushboolean(L, instance->pauseAutoSaveTimer ? 1 : 0);
    return 1;
}

// --- Setters for SaveManager ---
static int SaveManager_set_currentGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->currentGame = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_saveVersion(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->saveVersion = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_localSavePath(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->localSavePath = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_userSavePath(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->userSavePath = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_signal(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->signal = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveManager_set_flags(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->flags = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveManager_set_delay(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->delay = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveManager_set_name(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->name = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_location(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->location = luaL_checkstring(L, 2);
    return 0;
}

static int SaveManager_set_autoSaveTimer(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->autoSaveTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int SaveManager_set_pauseAutoSaveTimer(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");
    instance->pauseAutoSaveTimer = lua_toboolean(L, 2) != 0;
    return 0;
}

int SaveManagerBinding::isVisible(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    int result = instance->isVisible();
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::showSave(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->showSave();
    return 0;
}

int SaveManagerBinding::showLoad(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->showLoad();
    return 0;
}

int SaveManagerBinding::showImport(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->showImport();
    return 0;
}

int SaveManagerBinding::hide(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->hide();
    return 0;
}

int SaveManagerBinding::newGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string startId = luaL_checkstring(L, 2);
    instance->newGame(startId);
    return 0;
}

int SaveManagerBinding::save(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string s = luaL_checkstring(L, 2);
    bool autosave = lua_toboolean(L, 3) != 0;
    instance->save(s, autosave);
    return 0;
}

int SaveManagerBinding::savesExist(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    bool result = instance->savesExist();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveManagerBinding::saveExists(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string location = luaL_checkstring(L, 2);
    std::string name = luaL_checkstring(L, 3);
    bool result = instance->saveExists(location, name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveManagerBinding::execute(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->execute();
    return 0;
}

int SaveManagerBinding::versionCode(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string version = luaL_checkstring(L, 2);
    unsigned int result = instance->versionCode(version);
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::updateAutoSave(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->updateAutoSave();
    return 0;
}

int SaveManagerBinding::initialisePaths(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->initialisePaths();
    return 0;
}

int SaveManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    SaveManager* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SaveManagerBinding::_DESTRUCTOR(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SaveManagerBinding::saveGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string location = luaL_checkstring(L, 2);
    std::string name = luaL_checkstring(L, 3);
    int result = instance->saveGame(location, name);
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::loadGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string location = luaL_checkstring(L, 2);
    std::string name = luaL_checkstring(L, 3);
    int result = instance->loadGame(location, name);
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::importGame(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string location = luaL_checkstring(L, 2);
    std::string name = luaL_checkstring(L, 3);
    int flags = (int)luaL_checkinteger(L, 4);
    int result = instance->importGame(location, name, flags);
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::importPlayerBuildings(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string path = luaL_checkstring(L, 2);
    std::string file = luaL_checkstring(L, 3);
    int result = instance->importPlayerBuildings(path, file);
    lua_pushinteger(L, result);
    return 1;
}

int SaveManagerBinding::importOldPlayerBuildings(lua_State* L)
{
    SaveManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveManager is nil");

    std::string path = luaL_checkstring(L, 2);
    std::string name = luaL_checkstring(L, 3);
    int result = instance->importOldPlayerBuildings(path, name);
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 26: SaveManager* getSingleton(...) - static method
  line 34: void load(...) - overloaded method
  line 35: void load(...) - overloaded method
  line 36: void import(...) - unsupported arg type
  line 39: int scanGames(...) - overloaded method
  line 40: int scanGames(...) - overloaded method
  line 41: bool loadInfo(...) - unsupported arg type
  line 42: bool checkVersion(...) - unsupported arg type
  line 44: const std::string& getCurrentGame(...) - reference return type
  line 47: const std::string& getSavePath(...) - reference return type
*/

int SaveManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SaveManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SaveManager object");
    return 1;
}

void SaveManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SaveManagerBinding::gc },
        { "__tostring", SaveManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isVisible", SaveManagerBinding::isVisible },
        { "showSave", SaveManagerBinding::showSave },
        { "showLoad", SaveManagerBinding::showLoad },
        { "showImport", SaveManagerBinding::showImport },
        { "hide", SaveManagerBinding::hide },
        { "newGame", SaveManagerBinding::newGame },
        { "save", SaveManagerBinding::save },
        { "savesExist", SaveManagerBinding::savesExist },
        { "saveExists", SaveManagerBinding::saveExists },
        { "execute", SaveManagerBinding::execute },
        { "versionCode", SaveManagerBinding::versionCode },
        { "updateAutoSave", SaveManagerBinding::updateAutoSave },
        { "initialisePaths", SaveManagerBinding::initialisePaths },
        { "_CONSTRUCTOR", SaveManagerBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SaveManagerBinding::_DESTRUCTOR },
        { "saveGame", SaveManagerBinding::saveGame },
        { "loadGame", SaveManagerBinding::loadGame },
        { "importGame", SaveManagerBinding::importGame },
        { "importPlayerBuildings", SaveManagerBinding::importPlayerBuildings },
        { "importOldPlayerBuildings", SaveManagerBinding::importOldPlayerBuildings },
        { 0, 0 }
    };

    registerClass(
        L, 
        SaveManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SaveManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SaveManager_get_currentGame);
    lua_setfield(L, -2, "currentGame");
    lua_pushcfunction(L, SaveManager_get_saveVersion);
    lua_setfield(L, -2, "saveVersion");
    lua_pushcfunction(L, SaveManager_get_localSavePath);
    lua_setfield(L, -2, "localSavePath");
    lua_pushcfunction(L, SaveManager_get_userSavePath);
    lua_setfield(L, -2, "userSavePath");
    lua_pushcfunction(L, SaveManager_get_signal);
    lua_setfield(L, -2, "signal");
    lua_pushcfunction(L, SaveManager_get_flags);
    lua_setfield(L, -2, "flags");
    lua_pushcfunction(L, SaveManager_get_delay);
    lua_setfield(L, -2, "delay");
    lua_pushcfunction(L, SaveManager_get_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, SaveManager_get_location);
    lua_setfield(L, -2, "location");
    lua_pushcfunction(L, SaveManager_get_loadMenu);
    lua_setfield(L, -2, "loadMenu");
    lua_pushcfunction(L, SaveManager_get_saveMenu);
    lua_setfield(L, -2, "saveMenu");
    lua_pushcfunction(L, SaveManager_get_importMenu);
    lua_setfield(L, -2, "importMenu");
    lua_pushcfunction(L, SaveManager_get_autoSaveTimer);
    lua_setfield(L, -2, "autoSaveTimer");
    lua_pushcfunction(L, SaveManager_get_pauseAutoSaveTimer);
    lua_setfield(L, -2, "pauseAutoSaveTimer");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SaveManager_set_currentGame);
    lua_setfield(L, -2, "currentGame");
    lua_pushcfunction(L, SaveManager_set_saveVersion);
    lua_setfield(L, -2, "saveVersion");
    lua_pushcfunction(L, SaveManager_set_localSavePath);
    lua_setfield(L, -2, "localSavePath");
    lua_pushcfunction(L, SaveManager_set_userSavePath);
    lua_setfield(L, -2, "userSavePath");
    lua_pushcfunction(L, SaveManager_set_signal);
    lua_setfield(L, -2, "signal");
    lua_pushcfunction(L, SaveManager_set_flags);
    lua_setfield(L, -2, "flags");
    lua_pushcfunction(L, SaveManager_set_delay);
    lua_setfield(L, -2, "delay");
    lua_pushcfunction(L, SaveManager_set_name);
    lua_setfield(L, -2, "name");
    lua_pushcfunction(L, SaveManager_set_location);
    lua_setfield(L, -2, "location");
    lua_pushcfunction(L, SaveManager_set_autoSaveTimer);
    lua_setfield(L, -2, "autoSaveTimer");
    lua_pushcfunction(L, SaveManager_set_pauseAutoSaveTimer);
    lua_setfield(L, -2, "pauseAutoSaveTimer");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, SaveManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
