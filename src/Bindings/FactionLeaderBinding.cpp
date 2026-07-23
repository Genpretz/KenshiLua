#include "pch.h"
#include "kenshi\FactionLeader.h"
#include "FactionLeaderBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Templates/LektorBinding.h"

namespace KenshiLua
{

static FactionLeader* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionLeader>(L, idx, FactionLeaderBinding::getMetatableName());
}

// --- Getters for FactionLeader ---
static int FactionLeader_get_faction(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return pushObject<Faction>(L, instance->faction, FactionBinding::getMetatableName());
}

static int FactionLeader_get_worstEnemy(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return pushObject<Faction>(L, instance->worstEnemy, FactionBinding::getMetatableName());
}

static int FactionLeader_get_biomeTerritory(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    return pushObject<lektor<GameData*>>(L, &instance->biomeTerritory, LektorPtrBinding<GameData*>::metaName);
}

// --- Setters for FactionLeader ---
static int FactionLeader_set_faction(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    instance->faction = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int FactionLeader_set_worstEnemy(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    instance->worstEnemy = lua_isnoneornil(L, 2) ? nullptr : checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    return 0;
}

static int FactionLeader_set_biomeTerritory(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");
    lektor<GameData*>* val = LektorPtrBinding<GameData*>::get(L, 2);
    if (!val) return luaL_error(L, "Expected lektor<GameData*>");
    instance->biomeTerritory = *val;
    return 0;
}

int FactionLeaderBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    FactionLeader* result = instance->_CONSTRUCTOR(f);
    return pushObject<FactionLeader>(L, result, FactionLeaderBinding::getMetatableName());
}

int FactionLeaderBinding::setNewLeader(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    Character* _a1 = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    instance->setNewLeader(_a1);
    return 0;
}

int FactionLeaderBinding::getEnemyMissionTargetList(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "out is nil");
    GameData* mission = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->getEnemyMissionTargetList(*out, mission);
    return 0;
}

int FactionLeaderBinding::getGUIData(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    DatapanelGUI* _a1 = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(_a1, cat);
    return 0;
}

int FactionLeaderBinding::_DESTRUCTOR(lua_State* L)
{
    FactionLeader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionLeader is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int FactionLeaderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionLeaderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionLeader object");
    return 1;
}

void FactionLeaderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionLeaderBinding::gc },
        { "__tostring", FactionLeaderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionLeaderBinding::_CONSTRUCTOR },
        { "setNewLeader", FactionLeaderBinding::setNewLeader },
        { "getEnemyMissionTargetList", FactionLeaderBinding::getEnemyMissionTargetList },
        { "getGUIData", FactionLeaderBinding::getGUIData },
        { "_DESTRUCTOR", FactionLeaderBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionLeaderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionLeaderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionLeader_get_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, FactionLeader_get_worstEnemy);
    lua_setfield(L, -2, "worstEnemy");
    lua_pushcfunction(L, FactionLeader_get_biomeTerritory);
    lua_setfield(L, -2, "biomeTerritory");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionLeader_set_faction);
    lua_setfield(L, -2, "faction");
    lua_pushcfunction(L, FactionLeader_set_worstEnemy);
    lua_setfield(L, -2, "worstEnemy");
    lua_pushcfunction(L, FactionLeader_set_biomeTerritory);
    lua_setfield(L, -2, "biomeTerritory");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua