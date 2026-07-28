#include "pch.h"
#include "kenshi\gamedatamanager.h"
#include "GameDataManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"

namespace KenshiLua
{

static GameDataManager* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataManager>(L, idx, GameDataManagerBinding::getMetatableName());
}

// --- Getters for GameDataManager ---
// --- Setters for GameDataManager ---
int GameDataManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    GameDataManager* result = instance->_CONSTRUCTOR();
    return pushObject<GameDataManager>(L, result, GameDataManagerBinding::getMetatableName());
}

int GameDataManagerBinding::reloadGameData(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    std::string filename = luaL_checkstring(L, 2);
    bool isActive = lua_toboolean(L, 3) != 0;
    bool _baseData = lua_toboolean(L, 4) != 0;
    bool result = instance->reloadGameData(filename, isActive, _baseData);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int GameDataManagerBinding::postProcessingTheDatas(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    instance->postProcessingTheDatas();
    return 0;
}

int GameDataManagerBinding::getMapSector(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    int x = (int)luaL_checkinteger(L, 2);
    int y = (int)luaL_checkinteger(L, 3);
    GameData* result = instance->getMapSector(x, y);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int GameDataManagerBinding::updateDatasOfType(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    GameDataContainer* fromcontainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool isMod = lua_toboolean(L, 4) != 0;
    instance->updateDatasOfType(fromcontainer, type, isMod);
    return 0;
}

int GameDataManagerBinding::updateData(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    GameData* from = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool isMod = lua_toboolean(L, 3) != 0;
    instance->updateData(from, isMod);
    return 0;
}

int GameDataManagerBinding::_DESTRUCTOR(lua_State* L)
{
    GameDataManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 80: void getBuildings(...) - unsupported arg type
*/

int GameDataManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int GameDataManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataManager object");
    return 1;
}

void GameDataManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataManagerBinding::gc },
        { "__tostring", GameDataManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", GameDataManagerBinding::_CONSTRUCTOR },
        { "reloadGameData", GameDataManagerBinding::reloadGameData },
        { "postProcessingTheDatas", GameDataManagerBinding::postProcessingTheDatas },
        { "getMapSector", GameDataManagerBinding::getMapSector },
        { "updateDatasOfType", GameDataManagerBinding::updateDatasOfType },
        { "updateData", GameDataManagerBinding::updateData },
        { "_DESTRUCTOR", GameDataManagerBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to GameDataContainer
    // setMetatableParent(L, GameDataManagerBinding::getMetatableName(), GameDataContainerBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua