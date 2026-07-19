#include "pch.h"
#include "kenshi\SaveFileSystem.h"
#include "SaveFileSystemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static SaveFileSystem* getInstance(lua_State* L, int idx)
{
    return checkObject<SaveFileSystem>(L, idx, SaveFileSystemBinding::getMetatableName());
}

// --- Getters for SaveFileSystem ---
static int SaveFileSystem_get_currentSave(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushstring(L, instance->currentSave.c_str());
    return 1;
}

static int SaveFileSystem_get_currentFolder(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushstring(L, instance->currentFolder.c_str());
    return 1;
}

static int SaveFileSystem_get_tempFolder(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushstring(L, instance->tempFolder.c_str());
    return 1;
}

static int SaveFileSystem_get_currentPathIndex(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushinteger(L, instance->currentPathIndex);
    return 1;
}

static int SaveFileSystem_get_currentMutex(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushlightuserdata(L, (void*)&instance->currentMutex);
    return 1;
}

static int SaveFileSystem_get_savingIcon(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushlightuserdata(L, (void*)instance->savingIcon);
    return 1;
}

static int SaveFileSystem_get_state(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushinteger(L, (lua_Integer)instance->state);
    return 1;
}

static int SaveFileSystem_get_failedToCopyError(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    lua_pushstring(L, instance->failedToCopyError.c_str());
    return 1;
}

// --- Setters for SaveFileSystem ---
static int SaveFileSystem_set_currentSave(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->currentSave = luaL_checkstring(L, 2);
    return 0;
}

static int SaveFileSystem_set_currentFolder(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->currentFolder = luaL_checkstring(L, 2);
    return 0;
}

static int SaveFileSystem_set_tempFolder(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->tempFolder = luaL_checkstring(L, 2);
    return 0;
}

static int SaveFileSystem_set_currentPathIndex(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->currentPathIndex = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveFileSystem_set_currentMutex(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for currentMutex");
}

static int SaveFileSystem_set_state(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->state = (SaveFileSystem::State)luaL_checkinteger(L, 2);
    return 0;
}

static int SaveFileSystem_set_failedToCopyError(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");
    instance->failedToCopyError = luaL_checkstring(L, 2);
    return 0;
}

int SaveFileSystemBinding::_CONSTRUCTOR(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    SaveFileSystem* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int SaveFileSystemBinding::_DESTRUCTOR(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int SaveFileSystemBinding::log(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string message = luaL_checkstring(L, 2);
    Logger::Severity level = (Logger::Severity)luaL_checkinteger(L, 3);
    instance->log(message, level);
    return 0;
}

int SaveFileSystemBinding::setTemporaryPath(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string path = luaL_checkstring(L, 2);
    instance->setTemporaryPath(path);
    return 0;
}

int SaveFileSystemBinding::fileExists(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string name = luaL_checkstring(L, 2);
    bool result = instance->fileExists(name);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveFileSystemBinding::readFile(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string name = luaL_checkstring(L, 2);
    std::string result = instance->readFile(name);
    lua_pushstring(L, result.c_str());
    return 1;
}

int SaveFileSystemBinding::writeFile(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string name = luaL_checkstring(L, 2);
    std::string result = instance->writeFile(name);
    lua_pushstring(L, result.c_str());
    return 1;
}

int SaveFileSystemBinding::deleteFile(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string name = luaL_checkstring(L, 2);
    instance->deleteFile(name);
    return 0;
}

int SaveFileSystemBinding::newGame(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->newGame();
    return 0;
}

int SaveFileSystemBinding::loadGame(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string savePath = luaL_checkstring(L, 2);
    instance->loadGame(savePath);
    return 0;
}

int SaveFileSystemBinding::saveGame(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string savePath = luaL_checkstring(L, 2);
    bool result = instance->saveGame(savePath);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveFileSystemBinding::sync(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->sync();
    return 0;
}

int SaveFileSystemBinding::analyse(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->analyse();
    return 0;
}

int SaveFileSystemBinding::cleanup(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    bool full = lua_toboolean(L, 2) != 0;
    instance->cleanup(full);
    return 0;
}

int SaveFileSystemBinding::scanForResidualTempFolders(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->scanForResidualTempFolders();
    return 0;
}

int SaveFileSystemBinding::isTempFolder(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    std::string f = luaL_checkstring(L, 2);
    bool result = instance->isTempFolder(f);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveFileSystemBinding::busy(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    bool result = instance->busy();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int SaveFileSystemBinding::createCurrent(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    instance->createCurrent();
    return 0;
}

int SaveFileSystemBinding::threadProc(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int SaveFileSystemBinding::_NV_threadProc(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    unsigned long result = instance->_NV_threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int SaveFileSystemBinding::addMessage(lua_State* L)
{
    SaveFileSystem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SaveFileSystem is nil");

    SaveFileSystem::MessageType type = (SaveFileSystem::MessageType)luaL_checkinteger(L, 2);
    std::string src = luaL_checkstring(L, 3);
    std::string dst = luaL_checkstring(L, 4);
    instance->addMessage(type, src, dst);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 20: SaveFileSystem* getSingleton(...) - static method
  line 40: const std::string& getActiveSave(...) - reference return type
*/

/*
Skipped properties needing manual binding:
  line 45: fileSystem (std::map<std::string, int, std::less<std::string >, Ogre::STLAllocator<std::pair<std::string const, int>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 46: deletedFiles (boost::unordered::unordered_set<std::string, boost::hash<std::string >, std::equal_to<std::string >, Ogre::STLAllocator<std::string, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 47: paths (lektor<std::string >) - unsupported type
  line 48: oldCurrentFolders (lektor<std::string >) - unsupported type
  line 75: messages (lektor<SaveFileSystem::FileMessage>) - unsupported type
  line 86: saveLog (std::basic_ofstream<char, std::char_traits<char> >) - unsupported type
*/

int SaveFileSystemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int SaveFileSystemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SaveFileSystem object");
    return 1;
}

void SaveFileSystemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SaveFileSystemBinding::gc },
        { "__tostring", SaveFileSystemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", SaveFileSystemBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", SaveFileSystemBinding::_DESTRUCTOR },
        { "log", SaveFileSystemBinding::log },
        { "setTemporaryPath", SaveFileSystemBinding::setTemporaryPath },
        { "fileExists", SaveFileSystemBinding::fileExists },
        { "readFile", SaveFileSystemBinding::readFile },
        { "writeFile", SaveFileSystemBinding::writeFile },
        { "deleteFile", SaveFileSystemBinding::deleteFile },
        { "newGame", SaveFileSystemBinding::newGame },
        { "loadGame", SaveFileSystemBinding::loadGame },
        { "saveGame", SaveFileSystemBinding::saveGame },
        { "sync", SaveFileSystemBinding::sync },
        { "analyse", SaveFileSystemBinding::analyse },
        { "cleanup", SaveFileSystemBinding::cleanup },
        { "scanForResidualTempFolders", SaveFileSystemBinding::scanForResidualTempFolders },
        { "isTempFolder", SaveFileSystemBinding::isTempFolder },
        { "busy", SaveFileSystemBinding::busy },
        { "createCurrent", SaveFileSystemBinding::createCurrent },
        { "threadProc", SaveFileSystemBinding::threadProc },
        { "_NV_threadProc", SaveFileSystemBinding::_NV_threadProc },
        { "addMessage", SaveFileSystemBinding::addMessage },
        { 0, 0 }
    };

    registerClass(
        L, 
        SaveFileSystemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SaveFileSystemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, SaveFileSystem_get_currentSave);
    lua_setfield(L, -2, "currentSave");
    lua_pushcfunction(L, SaveFileSystem_get_currentFolder);
    lua_setfield(L, -2, "currentFolder");
    lua_pushcfunction(L, SaveFileSystem_get_tempFolder);
    lua_setfield(L, -2, "tempFolder");
    lua_pushcfunction(L, SaveFileSystem_get_currentPathIndex);
    lua_setfield(L, -2, "currentPathIndex");
    lua_pushcfunction(L, SaveFileSystem_get_currentMutex);
    lua_setfield(L, -2, "currentMutex");
    lua_pushcfunction(L, SaveFileSystem_get_savingIcon);
    lua_setfield(L, -2, "savingIcon");
    lua_pushcfunction(L, SaveFileSystem_get_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, SaveFileSystem_get_failedToCopyError);
    lua_setfield(L, -2, "failedToCopyError");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, SaveFileSystem_set_currentSave);
    lua_setfield(L, -2, "currentSave");
    lua_pushcfunction(L, SaveFileSystem_set_currentFolder);
    lua_setfield(L, -2, "currentFolder");
    lua_pushcfunction(L, SaveFileSystem_set_tempFolder);
    lua_setfield(L, -2, "tempFolder");
    lua_pushcfunction(L, SaveFileSystem_set_currentPathIndex);
    lua_setfield(L, -2, "currentPathIndex");
    lua_pushcfunction(L, SaveFileSystem_set_currentMutex);
    lua_setfield(L, -2, "currentMutex");
    lua_pushcfunction(L, SaveFileSystem_set_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, SaveFileSystem_set_failedToCopyError);
    lua_setfield(L, -2, "failedToCopyError");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to ThreadClass
    // setMetatableParent(L, SaveFileSystemBinding::getMetatableName(), ThreadClassBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
