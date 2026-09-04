#include "pch.h"
#include "kenshi\FactionUniqueSquadManager.h"
#include "UniqueSpawnDataBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"

namespace KenshiLua
{

typedef FactionUniqueSquadManager::UniqueSpawnData UniqueSpawnData;

static UniqueSpawnData* getInstance(lua_State* L, int idx)
{
    return checkObject<UniqueSpawnData>(L, idx, UniqueSpawnDataBinding::getMetatableName());
}

// --- Getters for UniqueSpawnData ---
static int UniqueSpawnData_get_squadTemplate(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    return pushObject<GameData>(L, instance->squadTemplate, GameDataBinding::getMetatableName());
}

static int UniqueSpawnData_get_desiredNumberToHave(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    lua_pushinteger(L, instance->desiredNumberToHave);
    return 1;
}

static int UniqueSpawnData_get_respawnTimer(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    lua_pushnumber(L, instance->respawnTimer);
    return 1;
}

static int UniqueSpawnData_get_existingSquadsList(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    return pushObject<lektor<hand>>(L, &instance->existingSquadsList, LektorValueReadOnlyBinding<hand>::metaName);
}

// --- Setters for UniqueSpawnData ---
static int UniqueSpawnData_set_squadTemplate(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    instance->squadTemplate = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int UniqueSpawnData_set_desiredNumberToHave(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    instance->desiredNumberToHave = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int UniqueSpawnData_set_respawnTimer(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    instance->respawnTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

static int UniqueSpawnData_set_existingSquadsList(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");
    lektor<hand>* val = checkObject<lektor<hand>>(L, 2, LektorValueReadOnlyBinding<hand>::metaName);
    if (!val) return luaL_error(L, "Expected lektor<hand> object");
    instance->existingSquadsList = *val;
    return 0;
}

int UniqueSpawnDataBinding::currentNumber(lua_State* L)
{
    UniqueSpawnData* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "UniqueSpawnData is nil");

    int result = instance->currentNumber();
    lua_pushinteger(L, result);
    return 1;
}

int UniqueSpawnDataBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int UniqueSpawnDataBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.UniqueSpawnData object");
    return 1;
}

void UniqueSpawnDataBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       UniqueSpawnDataBinding::gc },
        { "__tostring", UniqueSpawnDataBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "currentNumber", UniqueSpawnDataBinding::currentNumber },
        { 0, 0 }
    };

    registerClass(
        L, 
        UniqueSpawnDataBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, UniqueSpawnDataBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "squadTemplate", UniqueSpawnData_get_squadTemplate);
    registerGetter(L, "desiredNumberToHave", UniqueSpawnData_get_desiredNumberToHave);
    registerGetter(L, "respawnTimer", UniqueSpawnData_get_respawnTimer);
    registerGetter(L, "existingSquadsList", UniqueSpawnData_get_existingSquadsList);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "squadTemplate", UniqueSpawnData_set_squadTemplate);
    registerSetter(L, "desiredNumberToHave", UniqueSpawnData_set_desiredNumberToHave);
    registerSetter(L, "respawnTimer", UniqueSpawnData_set_respawnTimer);
    registerSetter(L, "existingSquadsList", UniqueSpawnData_set_existingSquadsList);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua