#include "pch.h"
#include "kenshi/Dialogue.h"
#include "DialogDataManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/DialogLineDataBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static DialogDataManager* getInstance(lua_State* L, int idx)
{
    return checkObject<DialogDataManager>(L, idx, DialogDataManagerBinding::getMetatableName());
}

int DialogDataManagerBinding::_createData(lua_State* L)
{
    GameData* d = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    DialogLineData* res = DialogDataManager::_createData(d);
    return pushObject<DialogLineData>(L, res, DialogLineDataBinding::getMetatableName());
}

int DialogDataManagerBinding::initialise(lua_State* L)
{
    DialogDataManager::initialise();
    return 0;
}

int DialogDataManagerBinding::save(lua_State* L)
{
    GameData* d = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    DialogDataManager::save(d);
    return 0;
}

int DialogDataManagerBinding::load(lua_State* L)
{
    GameData* d = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    DialogDataManager::load(d);
    return 0;
}

int DialogDataManagerBinding::newGameReset(lua_State* L)
{
    DialogDataManager::newGameReset();
    return 0;
}

int DialogDataManagerBinding::getData(lua_State* L)
{
    GameData* d = checkObject<GameData>(L, 1, GameDataBinding::getMetatableName());
    DialogLineData* res = DialogDataManager::getData(d);
    return pushObject<DialogLineData>(L, res, DialogLineDataBinding::getMetatableName());
}

int DialogDataManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int DialogDataManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.DialogDataManager object");
    return 1;
}

void DialogDataManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       DialogDataManagerBinding::gc },
        { "__tostring", DialogDataManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_createData", DialogDataManagerBinding::_createData },
        { "initialise",  DialogDataManagerBinding::initialise },
        { "save",        DialogDataManagerBinding::save },
        { "load",        DialogDataManagerBinding::load },
        { "newGameReset",DialogDataManagerBinding::newGameReset },
        { "getData",     DialogDataManagerBinding::getData },
        { 0, 0 }
    };

    registerClass(
        L, 
        DialogDataManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, DialogDataManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua