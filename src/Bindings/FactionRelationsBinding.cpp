#include "pch.h"
#include <kenshi/FactionRelations.h>
#include "FactionRelationsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/RelationDataBinding.h"
#include "Bindings/Gui/DatapanelGUIBinding.h"
#include "Bindings/Templates/OgreUnorderedBinding.h"

namespace KenshiLua
{

template <>
struct LuaCodec<FactionRelations::RelationData>
{
    static void push(lua_State* L, const FactionRelations::RelationData& val, const char* meta)
    {
        FactionRelations::RelationData* copy = new FactionRelations::RelationData(val);
        pushObject<FactionRelations::RelationData>(L, copy, meta);
    }

    static FactionRelations::RelationData read(lua_State* L, int idx, const char* meta)
    {
        FactionRelations::RelationData* ptr = checkObject<FactionRelations::RelationData>(L, idx, meta);
        return ptr ? *ptr : FactionRelations::RelationData();
    }
};

static FactionRelations* getInstance(lua_State* L, int idx)
{
    return checkObject<FactionRelations>(L, idx, FactionRelationsBinding::getMetatableName());
}

// --- Getters for FactionRelations ---
static int FactionRelations_get_me(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return pushObject<Faction>(L, instance->me, FactionBinding::getMetatableName());
}

static int FactionRelations_get_playerRank(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushinteger(L, instance->playerRank);
    return 1;
}

static int FactionRelations_get_globalReputationTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->globalReputationTrust);
    return 1;
}

static int FactionRelations_get_globalReputationForBadassery(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->globalReputationForBadassery);
    return 1;
}

static int FactionRelations_get__factionRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return pushObject<ogre_unordered_map<Faction*, FactionRelations::RelationData>::type>(
        L, 
        &instance->_factionRelations, 
        "KenshiLua.FactionRelationDataMap"
    );
}

static int FactionRelations_get_defaultFactionRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    lua_pushnumber(L, instance->defaultFactionRelation);
    return 1;
}

// --- Setters for FactionRelations ---
static int FactionRelations_set_me(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* f = nullptr;
    if (!lua_isnil(L, 2)) {
        f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    }
    instance->me = f;
    return 0;
}

static int FactionRelations_set_playerRank(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->playerRank = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int FactionRelations_set_globalReputationTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->globalReputationTrust = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FactionRelations_set_globalReputationForBadassery(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->globalReputationForBadassery = (float)luaL_checknumber(L, 2);
    return 0;
}

static int FactionRelations_set__factionRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    return luaL_error(L, "Read-only or unsupported setter type for _factionRelations");
}

static int FactionRelations_set_defaultFactionRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    instance->defaultFactionRelation = (float)luaL_checknumber(L, 2);
    return 0;
}

int FactionRelationsBinding::_CONSTRUCTOR(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    FactionRelations* result = instance->_CONSTRUCTOR();
    return pushObject<FactionRelations>(L, result, FactionRelationsBinding::getMetatableName());
}

int FactionRelationsBinding::setupPhase2(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->setupPhase2();
    return 0;
}

int FactionRelationsBinding::isEnemyByDefault(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    bool result = instance->isEnemyByDefault();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::reset(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->reset();
    return 0;
}

int FactionRelationsBinding::update(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->update();
    return 0;
}

int FactionRelationsBinding::_NV_update(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->_NV_update();
    return 0;
}

int FactionRelationsBinding::_DESTRUCTOR(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");

    instance->_DESTRUCTOR();
    return 0;
}

static bool tryGetFactionEvent(lua_State* L, int idx, FactionRelations::FactionEvent& event)
{
    if (lua_isstring(L, idx)) {
        std::string str = lua_tostring(L, idx);
        if (str == "ATTACKED_US_DEFENSIVELY") { event = FactionRelations::ATTACKED_US_DEFENSIVELY; return true; }
        if (str == "ATTACKED_US_AGGRESSIVELY") { event = FactionRelations::ATTACKED_US_AGGRESSIVELY; return true; }
        if (str == "DEFEATED_ONE_OF_US_DEFENSIVELY") { event = FactionRelations::DEFEATED_ONE_OF_US_DEFENSIVELY; return true; }
        if (str == "DEFEATED_ONE_OF_US_AGGRESSIVELY") { event = FactionRelations::DEFEATED_ONE_OF_US_AGGRESSIVELY; return true; }
        if (str == "KILLED_ONE_OF_US_DIRECTLY") { event = FactionRelations::KILLED_ONE_OF_US_DIRECTLY; return true; }
        if (str == "KILLED_ONE_OF_US_INDIRECTLY") { event = FactionRelations::KILLED_ONE_OF_US_INDIRECTLY; return true; }
        if (str == "EXECUTED_ONE_OF_US") { event = FactionRelations::EXECUTED_ONE_OF_US; return true; }
        if (str == "AIDED_US_IN_BATTLE") { event = FactionRelations::AIDED_US_IN_BATTLE; return true; }
        if (str == "FIRST_AIDED_US") { event = FactionRelations::FIRST_AIDED_US; return true; }
        if (str == "TAKEN_TO_BED") { event = FactionRelations::TAKEN_TO_BED; return true; }
        if (str == "DEFEATED_AN_ENEMY") { event = FactionRelations::DEFEATED_AN_ENEMY; return true; }
        if (str == "KILLED_AN_ENEMY") { event = FactionRelations::KILLED_AN_ENEMY; return true; }
        if (str == "CAPTURED_US") { event = FactionRelations::CAPTURED_US; return true; }
    } else if (lua_isnumber(L, idx)) {
        double val = lua_tonumber(L, idx);
        if (val == (int)val && val >= 0 && val <= 12) {
            event = (FactionRelations::FactionEvent)(int)val;
            return true;
        }
    }
    return false;
}

int FactionRelationsBinding::setupPhase1(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setupPhase1(f);
    return 0;
}

int FactionRelationsBinding::save(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    GameData* factionsList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(factionsList);
    return 0;
}

int FactionRelationsBinding::_NV_save(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    GameData* factionsList = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_save(factionsList);
    return 0;
}

int FactionRelationsBinding::load(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    GameData* gamestate_faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool playerOnly = lua_toboolean(L, 3) != 0;
    instance->load(gamestate_faction, playerOnly);
    return 0;
}

int FactionRelationsBinding::_NV_load(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    GameData* gamestate_faction = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    bool playerOnly = lua_toboolean(L, 3) != 0;
    instance->_NV_load(gamestate_faction, playerOnly);
    return 0;
}

int FactionRelationsBinding::_isAlly(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->_isAlly(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::_isEnemy(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->_isEnemy(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::isEnemy(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->isEnemy(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::setEnemy(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setEnemy(c);
    return 0;
}

int FactionRelationsBinding::_NV_setEnemy(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->_NV_setEnemy(c);
    return 0;
}

int FactionRelationsBinding::isAlly(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->isAlly(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::isCoexisting(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* c = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    bool result = instance->isCoexisting(c);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::getFactionRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float result = instance->getFactionRelation(p);
    lua_pushnumber(L, result);
    return 1;
}

int FactionRelationsBinding::getFactionRelationMultiplier(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float result = instance->getFactionRelationMultiplier(p);
    lua_pushnumber(L, result);
    return 1;
}

int FactionRelationsBinding::getFactionRelationMultiplierInverse(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float result = instance->getFactionRelationMultiplierInverse(p);
    lua_pushnumber(L, result);
    return 1;
}

int FactionRelationsBinding::setRelation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* who = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float setTo = (float)luaL_checknumber(L, 3);
    instance->setRelation(who, setTo);
    return 0;
}

int FactionRelationsBinding::affectRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    
    FactionRelations::FactionEvent e;
    if (tryGetFactionEvent(L, 3, e)) {
        float mult = (float)luaL_checknumber(L, 4);
        instance->affectRelations(p, e, mult);
    } else {
        float amount = (float)luaL_checknumber(L, 3);
        float mult = (float)luaL_checknumber(L, 4);
        instance->affectRelations(p, amount, mult);
    }
    return 0;
}

int FactionRelationsBinding::_NV_affectRelations(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    
    FactionRelations::FactionEvent e;
    if (tryGetFactionEvent(L, 3, e)) {
        float mult = (float)luaL_checknumber(L, 4);
        instance->_NV_affectRelations(p, e, mult);
    } else {
        float amount = (float)luaL_checknumber(L, 3);
        float mult = (float)luaL_checknumber(L, 4);
        instance->_NV_affectRelations(p, amount, mult);
    }
    return 0;
}

int FactionRelationsBinding::affectTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    float mult = (float)luaL_checknumber(L, 4);
    instance->affectTrust(p, amount, mult);
    return 0;
}

int FactionRelationsBinding::_NV_affectTrust(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    float mult = (float)luaL_checknumber(L, 4);
    instance->_NV_affectTrust(p, amount, mult);
    return 0;
}

int FactionRelationsBinding::setNoLongerEnemies(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setNoLongerEnemies(p);
    return 0;
}

int FactionRelationsBinding::_NV_setNoLongerEnemies(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->_NV_setNoLongerEnemies(p);
    return 0;
}

int FactionRelationsBinding::declareWar(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->declareWar(p);
    return 0;
}

int FactionRelationsBinding::_NV_declareWar(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->_NV_declareWar(p);
    return 0;
}

int FactionRelationsBinding::affectReputation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->affectReputation(p, amount);
    return 0;
}

int FactionRelationsBinding::_NV_affectReputation(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    float amount = (float)luaL_checknumber(L, 3);
    instance->_NV_affectReputation(p, amount);
    return 0;
}

int FactionRelationsBinding::getRelationData(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    FactionRelations::RelationData* result = instance->getRelationData(p);
    return pushObject<FactionRelations::RelationData>(L, result, RelationDataBinding::getMetatableName());
}

int FactionRelationsBinding::_NV_getRelationData(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    FactionRelations::RelationData* result = instance->_NV_getRelationData(p);
    return pushObject<FactionRelations::RelationData>(L, result, RelationDataBinding::getMetatableName());
}

int FactionRelationsBinding::getGUIData(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    DatapanelGUI* panel = checkObject<DatapanelGUI>(L, 2, DatapanelGUIBinding::getMetatableName());
    int category = (int)luaL_checkinteger(L, 3);
    instance->getGUIData(panel, category);
    return 0;
}

int FactionRelationsBinding::getRelationsData(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    ogre_unordered_map<Faction*, float>::type* data = OgreUnorderedMapBinding<Faction*, float>::get(L, 2);
    instance->getRelationsData(*data);
    return 0;
}

int FactionRelationsBinding::checkStateCondition(lua_State* L)
{
    FactionRelations* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FactionRelations is nil");
    DialogConditionEnum conditionName = (DialogConditionEnum)luaL_checkinteger(L, 2);
    ComparisonEnum compareBy = (ComparisonEnum)luaL_checkinteger(L, 3);
    int val = (int)luaL_checkinteger(L, 4);
    Faction* yourFaction = checkObject<Faction>(L, 5, FactionBinding::getMetatableName());
    bool result = instance->checkStateCondition(conditionName, compareBy, val, yourFaction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int FactionRelationsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FactionRelationsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FactionRelations object");
    return 1;
}

void FactionRelationsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FactionRelationsBinding::gc },
        { "__tostring", FactionRelationsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", FactionRelationsBinding::_CONSTRUCTOR },
        { "setupPhase2", FactionRelationsBinding::setupPhase2 },
        { "isEnemyByDefault", FactionRelationsBinding::isEnemyByDefault },
        { "reset", FactionRelationsBinding::reset },
        { "update", FactionRelationsBinding::update },
        { "_NV_update", FactionRelationsBinding::_NV_update },
        { "_DESTRUCTOR", FactionRelationsBinding::_DESTRUCTOR },
        { "setupPhase1", FactionRelationsBinding::setupPhase1 },
        { "save", FactionRelationsBinding::save },
        { "_NV_save", FactionRelationsBinding::_NV_save },
        { "load", FactionRelationsBinding::load },
        { "_NV_load", FactionRelationsBinding::_NV_load },
        { "_isAlly", FactionRelationsBinding::_isAlly },
        { "_isEnemy", FactionRelationsBinding::_isEnemy },
        { "isEnemy", FactionRelationsBinding::isEnemy },
        { "setEnemy", FactionRelationsBinding::setEnemy },
        { "_NV_setEnemy", FactionRelationsBinding::_NV_setEnemy },
        { "isAlly", FactionRelationsBinding::isAlly },
        { "isCoexisting", FactionRelationsBinding::isCoexisting },
        { "getFactionRelation", FactionRelationsBinding::getFactionRelation },
        { "getFactionRelationMultiplier", FactionRelationsBinding::getFactionRelationMultiplier },
        { "getFactionRelationMultiplierInverse", FactionRelationsBinding::getFactionRelationMultiplierInverse },
        { "setRelation", FactionRelationsBinding::setRelation },
        { "affectRelations", FactionRelationsBinding::affectRelations },
        { "_NV_affectRelations", FactionRelationsBinding::_NV_affectRelations },
        { "affectTrust", FactionRelationsBinding::affectTrust },
        { "_NV_affectTrust", FactionRelationsBinding::_NV_affectTrust },
        { "setNoLongerEnemies", FactionRelationsBinding::setNoLongerEnemies },
        { "_NV_setNoLongerEnemies", FactionRelationsBinding::_NV_setNoLongerEnemies },
        { "declareWar", FactionRelationsBinding::declareWar },
        { "_NV_declareWar", FactionRelationsBinding::_NV_declareWar },
        { "affectReputation", FactionRelationsBinding::affectReputation },
        { "_NV_affectReputation", FactionRelationsBinding::_NV_affectReputation },
        { "getRelationData", FactionRelationsBinding::getRelationData },
        { "_NV_getRelationData", FactionRelationsBinding::_NV_getRelationData },
        { "getGUIData", FactionRelationsBinding::getGUIData },
        { "getRelationsData", FactionRelationsBinding::getRelationsData },
        { "checkStateCondition", FactionRelationsBinding::checkStateCondition },
        { 0, 0 }
    };

    registerClass(
        L, 
        FactionRelationsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FactionRelationsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FactionRelations_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionRelations_get_playerRank);
    lua_setfield(L, -2, "playerRank");
    lua_pushcfunction(L, FactionRelations_get_globalReputationTrust);
    lua_setfield(L, -2, "globalReputationTrust");
    lua_pushcfunction(L, FactionRelations_get_globalReputationForBadassery);
    lua_setfield(L, -2, "globalReputationForBadassery");
    lua_pushcfunction(L, FactionRelations_get__factionRelations);
    lua_setfield(L, -2, "_factionRelations");
    lua_pushcfunction(L, FactionRelations_get_defaultFactionRelation);
    lua_setfield(L, -2, "defaultFactionRelation");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FactionRelations_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FactionRelations_set_playerRank);
    lua_setfield(L, -2, "playerRank");
    lua_pushcfunction(L, FactionRelations_set_globalReputationTrust);
    lua_setfield(L, -2, "globalReputationTrust");
    lua_pushcfunction(L, FactionRelations_set_globalReputationForBadassery);
    lua_setfield(L, -2, "globalReputationForBadassery");
    lua_pushcfunction(L, FactionRelations_set__factionRelations);
    lua_setfield(L, -2, "_factionRelations");
    lua_pushcfunction(L, FactionRelations_set_defaultFactionRelation);
    lua_setfield(L, -2, "defaultFactionRelation");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    OgreUnorderedMapBinding<Faction*, float>::registerBinding(
        L, 
        "KenshiLua.FactionFloatMap", 
        FactionBinding::getMetatableName(), 
        nullptr
    );
    OgreUnorderedMapBinding<Faction*, FactionRelations::RelationData>::registerBinding(
        L, 
        "KenshiLua.FactionRelationDataMap", 
        FactionBinding::getMetatableName(), 
        RelationDataBinding::getMetatableName()
    );

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
