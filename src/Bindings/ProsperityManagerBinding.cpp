#include "pch.h"
#include "kenshi\FactionUniqueSquadManager.h"
#include "ProsperityManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static ProsperityManager* getInstance(lua_State* L, int idx)
{
    return checkObject<ProsperityManager>(L, idx, ProsperityManagerBinding::getMetatableName());
}

// --- Getters for ProsperityManager ---
static int ProsperityManager_get_actualProsperity(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");
    lua_pushnumber(L, instance->actualProsperity);
    return 1;
}

static int ProsperityManager_get_maxProsperity(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");
    lua_pushnumber(L, instance->maxProsperity);
    return 1;
}

// --- Setters for ProsperityManager ---
static int ProsperityManager_set_actualProsperity(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");
    instance->actualProsperity = (double)luaL_checknumber(L, 2);
    return 0;
}

static int ProsperityManager_set_maxProsperity(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");
    instance->maxProsperity = (float)luaL_checknumber(L, 2);
    return 0;
}

int ProsperityManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    ProsperityManager* result = instance->_CONSTRUCTOR();
    return pushObject<ProsperityManager>(L, result, ProsperityManagerBinding::getMetatableName());
}

int ProsperityManagerBinding::setup(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    GameData* faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->setup(faction);
    return 0;
}

int ProsperityManagerBinding::load(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(state);
    return 0;
}

int ProsperityManagerBinding::save(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(state);
    return 0;
}

int ProsperityManagerBinding::getProsperityMultiplier(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    float result = instance->getProsperityMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int ProsperityManagerBinding::getGUIData(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int cat = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, cat);
    return 0;
}

int ProsperityManagerBinding::update(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->update(time);
    return 0;
}

int ProsperityManagerBinding::notifySquadDefeated(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    GameData* squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->notifySquadDefeated(squadTemplate);
    return 0;
}

int ProsperityManagerBinding::notifySpecialNPCDead(lua_State* L)
{
    ProsperityManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ProsperityManager is nil");

    GameData* npc = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->notifySpecialNPCDead(npc);
    return 0;
}

int ProsperityManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ProsperityManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ProsperityManager object");
    return 1;
}

void ProsperityManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ProsperityManagerBinding::gc },
        { "__tostring", ProsperityManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", ProsperityManagerBinding::_CONSTRUCTOR },
        { "setup", ProsperityManagerBinding::setup },
        { "load", ProsperityManagerBinding::load },
        { "save", ProsperityManagerBinding::save },
        { "getProsperityMultiplier", ProsperityManagerBinding::getProsperityMultiplier },
        { "getGUIData", ProsperityManagerBinding::getGUIData },
        { "update", ProsperityManagerBinding::update },
        { "notifySquadDefeated", ProsperityManagerBinding::notifySquadDefeated },
        { "notifySpecialNPCDead", ProsperityManagerBinding::notifySpecialNPCDead },
        { 0, 0 }
    };

    registerClass(
        L, 
        ProsperityManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ProsperityManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ProsperityManager_get_actualProsperity);
    lua_setfield(L, -2, "actualProsperity");
    lua_pushcfunction(L, ProsperityManager_get_maxProsperity);
    lua_setfield(L, -2, "maxProsperity");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ProsperityManager_set_actualProsperity);
    lua_setfield(L, -2, "actualProsperity");
    lua_pushcfunction(L, ProsperityManager_set_maxProsperity);
    lua_setfield(L, -2, "maxProsperity");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua