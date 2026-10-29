#include "pch.h"
#include "kenshi/Campaign.h"
#include "GameDataScoredListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"

namespace KenshiLua
{

static GameDataScoredList* getInstance(lua_State* L, int idx)
{
    return checkObject<GameDataScoredList>(L, idx, GameDataScoredListBinding::getMetatableName());
}

int GameDataScoredListBinding::setupFromData(lua_State* L)
{
    GameDataScoredList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "GameDataScoredList is nil");
    GameData* spawnData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    std::string listname = luaL_checkstring(L, 3);
    itemType typ = (itemType)luaL_checkinteger(L, 4);
    instance->setupFromData(spawnData, listname, typ);
    return 0;
}

int GameDataScoredListBinding::gc(lua_State* L)
{
    return 0;
}

int GameDataScoredListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.GameDataScoredList object");
    return 1;
}

void GameDataScoredListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       GameDataScoredListBinding::gc },
        { "__tostring", GameDataScoredListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupFromData", GameDataScoredListBinding::setupFromData },
        { 0, 0 }
    };

    registerClass(
        L, 
        GameDataScoredListBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, GameDataScoredListBinding::getMetatableName());
    lua_newtable(L);
    lua_setfield(L, -2, "__getters");
    lua_newtable(L);
    lua_setfield(L, -2, "__setters");
    lua_pop(L, 1);
}

} // namespace KenshiLua
