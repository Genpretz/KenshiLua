#include "pch.h"
#include "kenshi\Platoon.h"
#include "PlatoonBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/Util/TimeOfDayBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/Util/YesNoMaybeBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "OwnershipsBinding.h"
#include "kenshi\GameSaveState.h"

namespace KenshiLua
{

static Platoon* getInstance(lua_State* L, int idx)
{
    return checkObject<Platoon>(L, idx, PlatoonBinding::getMetatableName());
}

// --- Getters for Platoon ---
static int Platoon_get_stringID(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushstring(L, instance->stringID.c_str());
    return 1;
}

static int Platoon_get__characterCountCurrent(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, instance->_characterCountCurrent);
    return 1;
}

static int Platoon_get__characterCountOriginal(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, instance->_characterCountOriginal);
    return 1;
}

static int Platoon_get_squadType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)instance->squadType);
    return 1;
}

static int Platoon_get_hasUniques(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<YesNoMaybe>(L, &instance->hasUniques, YesNoMaybeBinding::getMetatableName());
}

static int Platoon_get_speedOverride(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)instance->speedOverride);
    return 1;
}

static int Platoon_get_isSeparatedSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return handBinding::push(L, instance->isSeparatedSquad);
}

static int Platoon_get_canRefresh(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->canRefresh ? 1 : 0);
    return 1;
}

static int Platoon_get_regenerates(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->regenerates ? 1 : 0);
    return 1;
}

static int Platoon_get_myBaseHomeTownData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<GameData>(L, instance->myBaseHomeTownData, GameDataBinding::getMetatableName());
}

static int Platoon_get_priceMultWhenITrade(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushnumber(L, instance->priceMultWhenITrade);
    return 1;
}

static int Platoon_get__iBuyStolenGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->_iBuyStolenGoods ? 1 : 0);
    return 1;
}

static int Platoon_get__iBuyIllegalGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->_iBuyIllegalGoods ? 1 : 0);
    return 1;
}

static int Platoon_get_locatorModel(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushlightuserdata(L, (void*)instance->locatorModel);
    return 1;
}

static int Platoon_get_blackboard(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushlightuserdata(L, (void*)instance->blackboard);
    return 1;
}

static int Platoon_get__isIntact(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->_isIntact ? 1 : 0);
    return 1;
}

static int Platoon_get_squadTemplate(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<GameData>(L, instance->squadTemplate, GameDataBinding::getMetatableName());
}

static int Platoon_get_malnourishedLevel(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushnumber(L, instance->malnourishedLevel);
    return 1;
}

static int Platoon_get_hasNeverBeenActivated(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->hasNeverBeenActivated ? 1 : 0);
    return 1;
}

static int Platoon_get__persistentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->_persistentSquad ? 1 : 0);
    return 1;
}

static int Platoon_get_isResidentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->isResidentSquad ? 1 : 0);
    return 1;
}

static int Platoon_get_currentSpawnArea(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushlightuserdata(L, (void*)instance->currentSpawnArea);
    return 1;
}

static int Platoon_get_squadleader(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return handBinding::push(L, instance->squadleader);
}

static int Platoon_get_ownerships(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<Ownerships>(L, &instance->ownerships, OwnershipsBinding::getMetatableName());
}

static int Platoon_get_activePlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<ActivePlatoon>(L, instance->activePlatoon, ActivePlatoonBinding::getMetatableName());
}

static int Platoon_get_unloadedPlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushlightuserdata(L, (void*)instance->unloadedPlatoon);
    return 1;
}

static int Platoon_get_patrolSettings(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushlightuserdata(L, (void*)instance->patrolSettings);
    return 1;
}

static int Platoon_get_isDead(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->isDead ? 1 : 0);
    return 1;
}

static int Platoon_get_imprisoned(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, instance->imprisoned ? 1 : 0);
    return 1;
}

static int Platoon_get_index(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

static int Platoon_get_traderInventoryRefreshTime(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    return pushObject<TimeOfDay>(L, &instance->traderInventoryRefreshTime, TimeOfDayBinding::getMetatableName());
}

// --- Setters for Platoon ---
static int Platoon_set_stringID(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->stringID = luaL_checkstring(L, 2);
    return 0;
}

static int Platoon_set__characterCountCurrent(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_characterCountCurrent = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set__characterCountOriginal(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_characterCountOriginal = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_squadType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->squadType = (SquadType)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_hasUniques(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->hasUniques = *checkObject<YesNoMaybe>(L, 2, YesNoMaybeBinding::getMetatableName());
    return 0;
}

static int Platoon_set_speedOverride(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->speedOverride = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_isSeparatedSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->isSeparatedSquad = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Platoon_set_canRefresh(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->canRefresh = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_regenerates(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->regenerates = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_myBaseHomeTownData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->myBaseHomeTownData = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Platoon_set_priceMultWhenITrade(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->priceMultWhenITrade = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Platoon_set__iBuyStolenGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_iBuyStolenGoods = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set__iBuyIllegalGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_iBuyIllegalGoods = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set__isIntact(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_isIntact = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_squadTemplate(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->squadTemplate = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Platoon_set_malnourishedLevel(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->malnourishedLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Platoon_set_hasNeverBeenActivated(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->hasNeverBeenActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set__persistentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->_persistentSquad = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_isResidentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->isResidentSquad = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_squadleader(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->squadleader = *checkObject<hand>(L, 2, handBinding::getMetatableName());
    return 0;
}

static int Platoon_set_ownerships(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->ownerships = *checkObject<Ownerships>(L, 2, OwnershipsBinding::getMetatableName());
    return 0;
}

static int Platoon_set_activePlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->activePlatoon = lua_isnoneornil(L, 2) ? nullptr : checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

static int Platoon_set_isDead(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->isDead = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_imprisoned(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->imprisoned = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_index(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->index = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_traderInventoryRefreshTime(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->traderInventoryRefreshTime = *checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    return 0;
}

int PlatoonBinding::_CONSTRUCTOR(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    GameData* _squadTemplate = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    GameData* platoonState = checkObject<GameData>(L, 4, GameDataBinding::getMetatableName());
    Ogre::Vector3 p;
    readVector3(L, 5, p);
    bool _persistent = lua_toboolean(L, 6) != 0;
    Platoon* result = instance->_CONSTRUCTOR(f, _squadTemplate, platoonState, p, _persistent);
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int PlatoonBinding::_DESTRUCTOR(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int PlatoonBinding::setCharacterCount(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    int count = (int)luaL_checkinteger(L, 2);
    instance->setCharacterCount(count);
    return 0;
}

int PlatoonBinding::chooseNewHome(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    hand result = instance->chooseNewHome();
    return handBinding::push(L, result);
}

int PlatoonBinding::isUnconcious(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::_NV_isUnconcious(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::getSquadType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    SquadType result = instance->getSquadType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::setSquadType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    SquadType t = (SquadType)luaL_checkinteger(L, 2);
    instance->setSquadType(t);
    return 0;
}

int PlatoonBinding::getCurrentTownLocation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int PlatoonBinding::_NV_getCurrentTownLocation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int PlatoonBinding::hasCampaign(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    CampaignInstance* result = instance->hasCampaign();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::iBuyStolenGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool result = instance->iBuyStolenGoods(what);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::iBuyIllegalGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->iBuyIllegalGoods();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::setFaction(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setFaction(p);
    return 0;
}

int PlatoonBinding::_NV_setFaction(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Faction* p = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->_NV_setFaction(p);
    return 0;
}

int PlatoonBinding::canTakeRefugees(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool result = instance->canTakeRefugees(who);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::isUnique(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    UniquePlatoon* result = instance->isUnique();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::_NV_isUnique(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    UniquePlatoon* result = instance->_NV_isUnique();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::getPlatoonStringID(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    std::string result = instance->getPlatoonStringID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int PlatoonBinding::getBlackboard(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Blackboard* result = instance->getBlackboard();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::getDataType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    itemType result = instance->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::_NV_getDataType(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    itemType result = instance->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::erasePlatoonFile(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->erasePlatoonFile();
    return 0;
}

int PlatoonBinding::showDebugMarker(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->showDebugMarker(on);
    return 0;
}

int PlatoonBinding::getStateBroadcast(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    StateBroadcastData* result = instance->getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::_NV_getStateBroadcast(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    StateBroadcastData* result = instance->_NV_getStateBroadcast();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::serialiseEverything(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* result = instance->serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int PlatoonBinding::_NV_serialiseEverything(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* result = instance->_NV_serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int PlatoonBinding::loadStateData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadStateData(state);
    return 0;
}

int PlatoonBinding::_NV_loadStateData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadStateData(state);
    return 0;
}

int PlatoonBinding::loadFromSerialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int PlatoonBinding::_NV_loadFromSerialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int PlatoonBinding::reprocessTask(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->reprocessTask(t);
    return 0;
}

int PlatoonBinding::taskIsComplete(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->taskIsComplete(t);
    return 0;
}

int PlatoonBinding::setDataFilename(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    std::string f = luaL_checkstring(L, 2);
    instance->setDataFilename(f);
    return 0;
}

int PlatoonBinding::isIntact(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->isIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::notifyMissionEnded(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->notifyMissionEnded();
    return 0;
}

int PlatoonBinding::_NV_notifyMissionEnded(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->_NV_notifyMissionEnded();
    return 0;
}

int PlatoonBinding::activate(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->activate();
    return 0;
}

int PlatoonBinding::deactivate(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    GameDataContainer* forceCharacterStates = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    instance->deactivate(forceCharacterStates);
    return 0;
}

int PlatoonBinding::declareDead(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->declareDead();
    return 0;
}

int PlatoonBinding::undeclareDead(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->undeclareDead();
    return 0;
}

int PlatoonBinding::isFullyLoaded(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->isFullyLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::getActivePlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    ActivePlatoon* result = instance->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int PlatoonBinding::getUnloadedPlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    UnloadedPlatoon* result = instance->getUnloadedPlatoon();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::update(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::_NV_update(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::periodicUpdate_active(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->periodicUpdate_active(time);
    return 0;
}

int PlatoonBinding::_NV_periodicUpdate_active(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_periodicUpdate_active(time);
    return 0;
}

int PlatoonBinding::periodicUpdate_unloaded(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->periodicUpdate_unloaded();
    return 0;
}

int PlatoonBinding::_NV_periodicUpdate_unloaded(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->_NV_periodicUpdate_unloaded();
    return 0;
}

int PlatoonBinding::setupPatrolSettings(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    int minRange = (int)luaL_checkinteger(L, 2);
    int maxRange = (int)luaL_checkinteger(L, 3);
    instance->setupPatrolSettings(minRange, maxRange);
    return 0;
}

int PlatoonBinding::getPatrolInfo(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    PatrolInfo* result = instance->getPatrolInfo();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::getRoamingMapArea(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    AreaBiomeGroup* result = instance->getRoamingMapArea();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PlatoonBinding::isPersistentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool result = instance->isPersistentSquad();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::setPersistentSquad(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setPersistentSquad(on);
    return 0;
}

int PlatoonBinding::getOwnerships(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Ownerships* result = instance->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int PlatoonBinding::_NV_getOwnerships(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Ownerships* result = instance->_NV_getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int PlatoonBinding::getNearestActiveCharacter(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    Character* result = instance->getNearestActiveCharacter(p, floor);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlatoonBinding::getSquadLeader(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    Character* result = instance->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlatoonBinding::getCharacterCount(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    int result = instance->getCharacterCount();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::getCharacterCount_Original(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    int result = instance->getCharacterCount_Original();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::needsNewCharacters(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    int result = instance->needsNewCharacters();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::reCheckPersistenceOnUnload(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->reCheckPersistenceOnUnload();
    return 0;
}

int PlatoonBinding::_NV_reCheckPersistenceOnUnload(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");

    instance->_NV_reCheckPersistenceOnUnload();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 136: GameSaveState serialise(...) - unsupported arg type
  line 137: GameSaveState _NV_serialise(...) - unsupported arg type
  line 164: void setRoamingMapArea(...) - unsupported arg type
  line 176: const hand& getSquadLeader_theRealOne(...) - reference return type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Platoon_get_locatorModel: Ogre::Entity* (unbound pointer)
  - Platoon_get_blackboard: Blackboard* (unbound pointer)
  - Platoon_get_currentSpawnArea: AreaSector* (unbound pointer)
  - Platoon_get_unloadedPlatoon: UnloadedPlatoon* (unbound pointer)
  - Platoon_get_patrolSettings: PatrolInfo* (unbound pointer)
  - PlatoonBinding::hasCampaign: CampaignInstance* (unbound pointer)
  - PlatoonBinding::isUnique: UniquePlatoon* (unbound pointer)
  - PlatoonBinding::_NV_isUnique: UniquePlatoon* (unbound pointer)
  - PlatoonBinding::getBlackboard: Blackboard* (unbound pointer)
  - PlatoonBinding::getStateBroadcast: StateBroadcastData* (unbound pointer)
  - PlatoonBinding::_NV_getStateBroadcast: StateBroadcastData* (unbound pointer)
  - PlatoonBinding::getUnloadedPlatoon: UnloadedPlatoon* (unbound pointer)
  - PlatoonBinding::getPatrolInfo: PatrolInfo* (unbound pointer)
  - PlatoonBinding::getRoamingMapArea: AreaBiomeGroup* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 180: messageOnActivation (PlatoonCreationMessage) - unsupported type
*/

int PlatoonBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PlatoonBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Platoon object");
    return 1;
}



static int Platoon__NV_getCurrentTownLocation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    TownBase* result = instance->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}


static int Platoon__NV_getStateBroadcast(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    StateBroadcastData* res = instance->_NV_getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon__NV_isUnique(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    UniquePlatoon* res = instance->_NV_isUnique();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon__NV_loadFromSerialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}


static int Platoon__NV_loadStateData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->_NV_loadStateData(state);
    return 0;
}


static int Platoon__NV_serialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = instance->_NV_serialise(container, refList, offsetPosToSubtract);
    GameSaveState* copy = new GameSaveState(res);
    return pushObject<GameSaveState>(L, copy, GameSaveStateBinding::getMetatableName());
}


static int Platoon__NV_serialiseEverything(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* res = instance->_NV_serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}


static int Platoon__NV_setFaction(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->_NV_setFaction(f);
    return 0;
}


static int Platoon_canTakeRefugees(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool res = instance->canTakeRefugees(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int Platoon_chooseNewHome(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    hand result = instance->chooseNewHome();
    handBinding::push(L, result);
    return 1;
}


static int Platoon_deactivate(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameDataContainer* forceCharacterStates = nullptr;
    if (lua_isuserdata(L, 2)) {
        forceCharacterStates = (GameDataContainer*)lua_touserdata(L, 2);
    } else if (!lua_isnil(L, 2)) {
        forceCharacterStates = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    }
    instance->deactivate(forceCharacterStates);
    return 0;
}


static int Platoon_getActivePlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    ActivePlatoon* result = instance->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}


static int Platoon_getBlackboard(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Blackboard* res = instance->getBlackboard();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_getCurrentTownLocation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    TownBase* result = instance->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}


static int Platoon_getPatrolInfo(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    PatrolInfo* res = instance->getPatrolInfo();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_getRoamingMapArea(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    AreaBiomeGroup* res = instance->getRoamingMapArea();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_getSquadLeader_theRealOne(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    const hand& result = instance->getSquadLeader_theRealOne();
    handBinding::push(L, result);
    return 1;
}


static int Platoon_getStateBroadcast(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    StateBroadcastData* res = instance->getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_getUnloadedPlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    UnloadedPlatoon* res = instance->getUnloadedPlatoon();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_get_messageOnActivation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)instance->messageOnActivation);
    return 1;
}


static int Platoon_hasCampaign(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    CampaignInstance* res = instance->hasCampaign();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_iBuyStolenGoods(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool res = instance->iBuyStolenGoods(what);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}


static int Platoon_isUnique(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    UniquePlatoon* res = instance->isUnique();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}


static int Platoon_loadFromSerialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}


static int Platoon_loadStateData(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->loadStateData(state);
    return 0;
}


static int Platoon_reprocessTask(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->reprocessTask(t);
    return 0;
}


static int Platoon_serialise(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = instance->serialise(container, refList, offsetPosToSubtract);
    GameSaveState* copy = new GameSaveState(res);
    return pushObject<GameSaveState>(L, copy, GameSaveStateBinding::getMetatableName());
}


static int Platoon_serialiseEverything(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* res = instance->serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}


static int Platoon_setFaction(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    instance->setFaction(f);
    return 0;
}


static int Platoon_setRoamingMapArea(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    AreaBiomeGroup* maparea = (AreaBiomeGroup*)lua_touserdata(L, 2);
    instance->setRoamingMapArea(maparea);
    return 0;
}


static int Platoon_set_blackboard(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->blackboard = (Blackboard*)lua_touserdata(L, 2);
    return 0;
}


static int Platoon_set_currentSpawnArea(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->currentSpawnArea = (AreaSector*)lua_touserdata(L, 2);
    return 0;
}


static int Platoon_set_locatorModel(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->locatorModel = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}


static int Platoon_set_messageOnActivation(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->messageOnActivation = (PlatoonCreationMessage)luaL_checkinteger(L, 2);
    return 0;
}


static int Platoon_set_patrolSettings(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->patrolSettings = (PatrolInfo*)lua_touserdata(L, 2);
    return 0;
}


static int Platoon_set_unloadedPlatoon(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    instance->unloadedPlatoon = (UnloadedPlatoon*)lua_touserdata(L, 2);
    return 0;
}


static int Platoon_taskIsComplete(lua_State* L)
{
    Platoon* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Platoon is nil");
    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    instance->taskIsComplete(t);
    return 0;
}


void PlatoonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PlatoonBinding::gc },
        { "__tostring", PlatoonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", PlatoonBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", PlatoonBinding::_DESTRUCTOR },
        { "setCharacterCount", PlatoonBinding::setCharacterCount },
        { "chooseNewHome", PlatoonBinding::chooseNewHome },
        { "isUnconcious", PlatoonBinding::isUnconcious },
        { "_NV_isUnconcious", PlatoonBinding::_NV_isUnconcious },
        { "getSquadType", PlatoonBinding::getSquadType },
        { "setSquadType", PlatoonBinding::setSquadType },
        { "getCurrentTownLocation", PlatoonBinding::getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", PlatoonBinding::_NV_getCurrentTownLocation },
        { "hasCampaign", PlatoonBinding::hasCampaign },
        { "iBuyStolenGoods", PlatoonBinding::iBuyStolenGoods },
        { "iBuyIllegalGoods", PlatoonBinding::iBuyIllegalGoods },
        { "setFaction", PlatoonBinding::setFaction },
        { "_NV_setFaction", PlatoonBinding::_NV_setFaction },
        { "canTakeRefugees", PlatoonBinding::canTakeRefugees },
        { "isUnique", PlatoonBinding::isUnique },
        { "_NV_isUnique", PlatoonBinding::_NV_isUnique },
        { "getPlatoonStringID", PlatoonBinding::getPlatoonStringID },
        { "getBlackboard", PlatoonBinding::getBlackboard },
        { "getDataType", PlatoonBinding::getDataType },
        { "_NV_getDataType", PlatoonBinding::_NV_getDataType },
        { "erasePlatoonFile", PlatoonBinding::erasePlatoonFile },
        { "showDebugMarker", PlatoonBinding::showDebugMarker },
        { "getStateBroadcast", PlatoonBinding::getStateBroadcast },
        { "_NV_getStateBroadcast", PlatoonBinding::_NV_getStateBroadcast },
        { "serialiseEverything", PlatoonBinding::serialiseEverything },
        { "_NV_serialiseEverything", PlatoonBinding::_NV_serialiseEverything },
        { "loadStateData", PlatoonBinding::loadStateData },
        { "_NV_loadStateData", PlatoonBinding::_NV_loadStateData },
        { "loadFromSerialise", PlatoonBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", PlatoonBinding::_NV_loadFromSerialise },
        { "reprocessTask", PlatoonBinding::reprocessTask },
        { "taskIsComplete", PlatoonBinding::taskIsComplete },
        { "setDataFilename", PlatoonBinding::setDataFilename },
        { "isIntact", PlatoonBinding::isIntact },
        { "notifyMissionEnded", PlatoonBinding::notifyMissionEnded },
        { "_NV_notifyMissionEnded", PlatoonBinding::_NV_notifyMissionEnded },
        { "activate", PlatoonBinding::activate },
        { "deactivate", PlatoonBinding::deactivate },
        { "declareDead", PlatoonBinding::declareDead },
        { "undeclareDead", PlatoonBinding::undeclareDead },
        { "isFullyLoaded", PlatoonBinding::isFullyLoaded },
        { "getActivePlatoon", PlatoonBinding::getActivePlatoon },
        { "getUnloadedPlatoon", PlatoonBinding::getUnloadedPlatoon },
        { "update", PlatoonBinding::update },
        { "_NV_update", PlatoonBinding::_NV_update },
        { "periodicUpdate_active", PlatoonBinding::periodicUpdate_active },
        { "_NV_periodicUpdate_active", PlatoonBinding::_NV_periodicUpdate_active },
        { "periodicUpdate_unloaded", PlatoonBinding::periodicUpdate_unloaded },
        { "_NV_periodicUpdate_unloaded", PlatoonBinding::_NV_periodicUpdate_unloaded },
        { "setupPatrolSettings", PlatoonBinding::setupPatrolSettings },
        { "getPatrolInfo", PlatoonBinding::getPatrolInfo },
        { "getRoamingMapArea", PlatoonBinding::getRoamingMapArea },
        { "isPersistentSquad", PlatoonBinding::isPersistentSquad },
        { "setPersistentSquad", PlatoonBinding::setPersistentSquad },
        { "getOwnerships", PlatoonBinding::getOwnerships },
        { "_NV_getOwnerships", PlatoonBinding::_NV_getOwnerships },
        { "getNearestActiveCharacter", PlatoonBinding::getNearestActiveCharacter },
        { "getSquadLeader", PlatoonBinding::getSquadLeader },
        { "getCharacterCount", PlatoonBinding::getCharacterCount },
        { "getCharacterCount_Original", PlatoonBinding::getCharacterCount_Original },
        { "needsNewCharacters", PlatoonBinding::needsNewCharacters },
        { "reCheckPersistenceOnUnload", PlatoonBinding::reCheckPersistenceOnUnload },
        { "_NV_reCheckPersistenceOnUnload", PlatoonBinding::_NV_reCheckPersistenceOnUnload },
                { "serialise", Platoon_serialise },
        { "_NV_serialise", Platoon__NV_serialise },
        { "setRoamingMapArea", Platoon_setRoamingMapArea },
        { "getSquadLeader_theRealOne", Platoon_getSquadLeader_theRealOne },
        { 0, 0 }
    };

    registerClass(
        L, 
        PlatoonBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PlatoonBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "stringID", Platoon_get_stringID);
    registerGetter(L, "_characterCountCurrent", Platoon_get__characterCountCurrent);
    registerGetter(L, "_characterCountOriginal", Platoon_get__characterCountOriginal);
    registerGetter(L, "squadType", Platoon_get_squadType);
    registerGetter(L, "hasUniques", Platoon_get_hasUniques);
    registerGetter(L, "speedOverride", Platoon_get_speedOverride);
    registerGetter(L, "isSeparatedSquad", Platoon_get_isSeparatedSquad);
    registerGetter(L, "canRefresh", Platoon_get_canRefresh);
    registerGetter(L, "regenerates", Platoon_get_regenerates);
    registerGetter(L, "myBaseHomeTownData", Platoon_get_myBaseHomeTownData);
    registerGetter(L, "priceMultWhenITrade", Platoon_get_priceMultWhenITrade);
    registerGetter(L, "_iBuyStolenGoods", Platoon_get__iBuyStolenGoods);
    registerGetter(L, "_iBuyIllegalGoods", Platoon_get__iBuyIllegalGoods);
    registerGetter(L, "locatorModel", Platoon_get_locatorModel);
    registerGetter(L, "blackboard", Platoon_get_blackboard);
    registerGetter(L, "_isIntact", Platoon_get__isIntact);
    registerGetter(L, "squadTemplate", Platoon_get_squadTemplate);
    registerGetter(L, "malnourishedLevel", Platoon_get_malnourishedLevel);
    registerGetter(L, "hasNeverBeenActivated", Platoon_get_hasNeverBeenActivated);
    registerGetter(L, "_persistentSquad", Platoon_get__persistentSquad);
    registerGetter(L, "isResidentSquad", Platoon_get_isResidentSquad);
    registerGetter(L, "currentSpawnArea", Platoon_get_currentSpawnArea);
    registerGetter(L, "squadleader", Platoon_get_squadleader);
    registerGetter(L, "ownerships", Platoon_get_ownerships);
    registerGetter(L, "activePlatoon", Platoon_get_activePlatoon);
    registerGetter(L, "unloadedPlatoon", Platoon_get_unloadedPlatoon);
    registerGetter(L, "patrolSettings", Platoon_get_patrolSettings);
    registerGetter(L, "isDead", Platoon_get_isDead);
    registerGetter(L, "imprisoned", Platoon_get_imprisoned);
    registerGetter(L, "index", Platoon_get_index);
    registerGetter(L, "traderInventoryRefreshTime", Platoon_get_traderInventoryRefreshTime);
        registerGetter(L, "messageOnActivation", Platoon_get_messageOnActivation);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "stringID", Platoon_set_stringID);
    registerSetter(L, "_characterCountCurrent", Platoon_set__characterCountCurrent);
    registerSetter(L, "_characterCountOriginal", Platoon_set__characterCountOriginal);
    registerSetter(L, "squadType", Platoon_set_squadType);
    registerSetter(L, "hasUniques", Platoon_set_hasUniques);
    registerSetter(L, "speedOverride", Platoon_set_speedOverride);
    registerSetter(L, "isSeparatedSquad", Platoon_set_isSeparatedSquad);
    registerSetter(L, "canRefresh", Platoon_set_canRefresh);
    registerSetter(L, "regenerates", Platoon_set_regenerates);
    registerSetter(L, "myBaseHomeTownData", Platoon_set_myBaseHomeTownData);
    registerSetter(L, "priceMultWhenITrade", Platoon_set_priceMultWhenITrade);
    registerSetter(L, "_iBuyStolenGoods", Platoon_set__iBuyStolenGoods);
    registerSetter(L, "_iBuyIllegalGoods", Platoon_set__iBuyIllegalGoods);
    registerSetter(L, "_isIntact", Platoon_set__isIntact);
    registerSetter(L, "squadTemplate", Platoon_set_squadTemplate);
    registerSetter(L, "malnourishedLevel", Platoon_set_malnourishedLevel);
    registerSetter(L, "hasNeverBeenActivated", Platoon_set_hasNeverBeenActivated);
    registerSetter(L, "_persistentSquad", Platoon_set__persistentSquad);
    registerSetter(L, "isResidentSquad", Platoon_set_isResidentSquad);
    registerSetter(L, "squadleader", Platoon_set_squadleader);
    registerSetter(L, "ownerships", Platoon_set_ownerships);
    registerSetter(L, "activePlatoon", Platoon_set_activePlatoon);
    registerSetter(L, "isDead", Platoon_set_isDead);
    registerSetter(L, "imprisoned", Platoon_set_imprisoned);
    registerSetter(L, "index", Platoon_set_index);
    registerSetter(L, "traderInventoryRefreshTime", Platoon_set_traderInventoryRefreshTime);
        registerSetter(L, "blackboard", Platoon_set_blackboard);
        registerSetter(L, "currentSpawnArea", Platoon_set_currentSpawnArea);
        registerSetter(L, "locatorModel", Platoon_set_locatorModel);
        registerSetter(L, "messageOnActivation", Platoon_set_messageOnActivation);
        registerSetter(L, "patrolSettings", Platoon_set_patrolSettings);
        registerSetter(L, "unloadedPlatoon", Platoon_set_unloadedPlatoon);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to RootObjectBase
    setMetatableParent(L, PlatoonBinding::getMetatableName(), RootObjectBaseBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua