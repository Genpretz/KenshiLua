#include "pch.h"
#include "kenshi\Platoon.h"
#include "kenshi\GameSaveState.h"
#include "PlatoonBinding.h"
#include "OwnershipsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/TaskerBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/GameDataContainerBinding.h"

namespace KenshiLua
{

static Platoon* getB(lua_State* L, int idx)
{
    return checkObject<Platoon>(L, idx, PlatoonBinding::getMetatableName());
}

// --- Getters for Platoon ---
static int Platoon_get_stringID(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushstring(L, b->stringID.c_str());
    return 1;
}

static int Platoon_get__characterCountCurrent(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, b->_characterCountCurrent);
    return 1;
}

static int Platoon_get__characterCountOriginal(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, b->_characterCountOriginal);
    return 1;
}

static int Platoon_get_squadType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)b->squadType);
    return 1;
}

static int Platoon_get_hasUniques(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)b->hasUniques.key);
    return 1;
}

static int Platoon_get_speedOverride(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)b->speedOverride);
    return 1;
}

static int Platoon_get_isSeparatedSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return handBinding::push(L, b->isSeparatedSquad);
}

static int Platoon_get_canRefresh(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->canRefresh ? 1 : 0);
    return 1;
}

static int Platoon_get_regenerates(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->regenerates ? 1 : 0);
    return 1;
}

static int Platoon_get_myBaseHomeTownData(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return pushObject<GameData>(L, b->myBaseHomeTownData, GameDataBinding::getMetatableName());
}

static int Platoon_get_priceMultWhenITrade(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushnumber(L, b->priceMultWhenITrade);
    return 1;
}

static int Platoon_get__iBuyStolenGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->_iBuyStolenGoods ? 1 : 0);
    return 1;
}

static int Platoon_get__iBuyIllegalGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->_iBuyIllegalGoods ? 1 : 0);
    return 1;
}

static int Platoon_get_locatorModel(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    if (b->locatorModel) lua_pushlightuserdata(L, b->locatorModel);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_get_blackboard(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    if (b->blackboard) lua_pushlightuserdata(L, b->blackboard);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_get__isIntact(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->_isIntact ? 1 : 0);
    return 1;
}

static int Platoon_get_squadTemplate(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return pushObject<GameData>(L, b->squadTemplate, GameDataBinding::getMetatableName());
}

static int Platoon_get_malnourishedLevel(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushnumber(L, b->malnourishedLevel);
    return 1;
}

static int Platoon_get_hasNeverBeenActivated(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->hasNeverBeenActivated ? 1 : 0);
    return 1;
}

static int Platoon_get__persistentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->_persistentSquad ? 1 : 0);
    return 1;
}

static int Platoon_get_isResidentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->isResidentSquad ? 1 : 0);
    return 1;
}

static int Platoon_get_messageOnActivation(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, (lua_Integer)b->messageOnActivation);
    return 1;
}

static int Platoon_get_currentSpawnArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    if (b->currentSpawnArea) lua_pushlightuserdata(L, b->currentSpawnArea);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_get_squadleader(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return handBinding::push(L, b->squadleader);
}

static int Platoon_get_ownerships(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return pushObject<Ownerships>(L, b->getOwnerships(), OwnershipsBinding::getMetatableName());
}

static int Platoon_get_activePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return pushObject<ActivePlatoon>(L, b->getActivePlatoon(), ActivePlatoonBinding::getMetatableName());
}

static int Platoon_get_unloadedPlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    if (b->unloadedPlatoon) lua_pushlightuserdata(L, b->unloadedPlatoon);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_get_patrolSettings(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    if (b->patrolSettings) lua_pushlightuserdata(L, b->patrolSettings);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_get_isDead(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->isDead ? 1 : 0);
    return 1;
}

static int Platoon_get_imprisoned(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushboolean(L, b->imprisoned ? 1 : 0);
    return 1;
}

static int Platoon_get_index(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushinteger(L, b->index);
    return 1;
}

static int Platoon_get_traderInventoryRefreshTime(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    lua_pushnumber(L, b->traderInventoryRefreshTime.time);
    return 1;
}

// --- Setters for Platoon ---
static int Platoon_set_stringID(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->stringID = luaL_checkstring(L, 2);
    return 0;
}

static int Platoon_set__characterCountCurrent(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_characterCountCurrent = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set__characterCountOriginal(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_characterCountOriginal = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_squadType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->squadType = (SquadType)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_hasUniques(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->hasUniques = YesNoMaybe((YesNoMaybe::ynm)luaL_checkinteger(L, 2));
    return 0;
}

static int Platoon_set_speedOverride(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->speedOverride = (MoveSpeed)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_isSeparatedSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->isSeparatedSquad = *val;
    return 0;
}

static int Platoon_set_canRefresh(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->canRefresh = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_regenerates(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->regenerates = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_myBaseHomeTownData(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->myBaseHomeTownData = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Platoon_set_priceMultWhenITrade(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->priceMultWhenITrade = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Platoon_set__iBuyStolenGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_iBuyStolenGoods = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set__iBuyIllegalGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_iBuyIllegalGoods = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_locatorModel(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->locatorModel = (Ogre::Entity*)lua_touserdata(L, 2);
    return 0;
}

static int Platoon_set_blackboard(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->blackboard = (Blackboard*)lua_touserdata(L, 2);
    return 0;
}

static int Platoon_set__isIntact(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_isIntact = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_squadTemplate(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->squadTemplate = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    return 0;
}

static int Platoon_set_malnourishedLevel(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->malnourishedLevel = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Platoon_set_hasNeverBeenActivated(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->hasNeverBeenActivated = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set__persistentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->_persistentSquad = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_isResidentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->isResidentSquad = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_messageOnActivation(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->messageOnActivation = (PlatoonCreationMessage)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_currentSpawnArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->currentSpawnArea = (AreaSector*)lua_touserdata(L, 2);
    return 0;
}

static int Platoon_set_squadleader(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->squadleader = *val;
    return 0;
}

static int Platoon_set_ownerships(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "ownerships is a read-only property");
}

static int Platoon_set_activePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->activePlatoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    return 0;
}

static int Platoon_set_unloadedPlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->unloadedPlatoon = (UnloadedPlatoon*)lua_touserdata(L, 2);
    return 0;
}

static int Platoon_set_patrolSettings(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->patrolSettings = (PatrolInfo*)lua_touserdata(L, 2);
    return 0;
}

static int Platoon_set_isDead(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->isDead = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_imprisoned(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->imprisoned = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Platoon_set_index(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->index = (short)luaL_checkinteger(L, 2);
    return 0;
}

static int Platoon_set_traderInventoryRefreshTime(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    b->traderInventoryRefreshTime.setTime(luaL_checknumber(L, 2));
    return 0;
}

int PlatoonBinding::_DESTRUCTOR(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->_DESTRUCTOR();
    return 0;
}

int PlatoonBinding::setCharacterCount(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    int count = (int)luaL_checkinteger(L, 2);
    b->setCharacterCount(count);
    return 0;
}

int PlatoonBinding::isUnconcious(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::_NV_isUnconcious(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->_NV_isUnconcious();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::getSquadType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    SquadType result = b->getSquadType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::setSquadType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    SquadType t = (SquadType)luaL_checkinteger(L, 2);
    b->setSquadType(t);
    return 0;
}

int PlatoonBinding::iBuyIllegalGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->iBuyIllegalGoods();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::getPlatoonStringID(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    std::string result = b->getPlatoonStringID();
    lua_pushstring(L, result.c_str());
    return 1;
}

int PlatoonBinding::getDataType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    itemType result = b->getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::_NV_getDataType(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    itemType result = b->_NV_getDataType();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int PlatoonBinding::erasePlatoonFile(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->erasePlatoonFile();
    return 0;
}

int PlatoonBinding::showDebugMarker(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->showDebugMarker(on);
    return 0;
}

int PlatoonBinding::setDataFilename(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    std::string f = luaL_checkstring(L, 2);
    b->setDataFilename(f);
    return 0;
}

int PlatoonBinding::isIntact(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->isIntact();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::notifyMissionEnded(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->notifyMissionEnded();
    return 0;
}

int PlatoonBinding::_NV_notifyMissionEnded(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->_NV_notifyMissionEnded();
    return 0;
}

int PlatoonBinding::activate(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->activate();
    return 0;
}

int PlatoonBinding::declareDead(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->declareDead();
    return 0;
}

int PlatoonBinding::undeclareDead(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->undeclareDead();
    return 0;
}

int PlatoonBinding::isFullyLoaded(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->isFullyLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::update(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::_NV_update(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::periodicUpdate_active(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->periodicUpdate_active(time);
    return 0;
}

int PlatoonBinding::_NV_periodicUpdate_active(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->_NV_periodicUpdate_active(time);
    return 0;
}

int PlatoonBinding::periodicUpdate_unloaded(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->periodicUpdate_unloaded();
    return 0;
}

int PlatoonBinding::_NV_periodicUpdate_unloaded(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->_NV_periodicUpdate_unloaded();
    return 0;
}

int PlatoonBinding::setupPatrolSettings(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    int minRange = (int)luaL_checkinteger(L, 2);
    int maxRange = (int)luaL_checkinteger(L, 3);
    b->setupPatrolSettings(minRange, maxRange);
    return 0;
}

int PlatoonBinding::isPersistentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool result = b->isPersistentSquad();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PlatoonBinding::setPersistentSquad(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->setPersistentSquad(on);
    return 0;
}

int PlatoonBinding::getOwnerships(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    Ownerships* result = b->getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int PlatoonBinding::_NV_getOwnerships(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    Ownerships* result = b->_NV_getOwnerships();
    return pushObject<Ownerships>(L, result, OwnershipsBinding::getMetatableName());
}

int PlatoonBinding::getNearestActiveCharacter(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    Ogre::Vector3 p;
    readVector3(L, 2, p);
    int floor = (int)luaL_checkinteger(L, 3);
    Character* result = b->getNearestActiveCharacter(p, floor);
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlatoonBinding::getSquadLeader(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    Character* result = b->getSquadLeader();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int PlatoonBinding::getCharacterCount(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    int result = b->getCharacterCount();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::getCharacterCount_Original(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    int result = b->getCharacterCount_Original();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::needsNewCharacters(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    int result = b->needsNewCharacters();
    lua_pushinteger(L, result);
    return 1;
}

int PlatoonBinding::reCheckPersistenceOnUnload(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->reCheckPersistenceOnUnload();
    return 0;
}

int PlatoonBinding::_NV_reCheckPersistenceOnUnload(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");

    b->_NV_reCheckPersistenceOnUnload();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 108: Platoon* _CONSTRUCTOR(...) - protected constructor
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Platoon_get_locatorModel / Platoon_set_locatorModel: Ogre::Entity*
  - Platoon_get_blackboard / Platoon_set_blackboard: Blackboard*
  - Platoon_get_currentSpawnArea / Platoon_set_currentSpawnArea: AreaSector*
  - Platoon_get_unloadedPlatoon / Platoon_set_unloadedPlatoon: UnloadedPlatoon*
  - Platoon_get_patrolSettings / Platoon_set_patrolSettings: PatrolInfo*
  - Platoon_hasCampaign: CampaignInstance*
  - Platoon_isUnique / Platoon__NV_isUnique: UniquePlatoon*
  - Platoon_getBlackboard: Blackboard*
  - Platoon_getStateBroadcast / Platoon__NV_getStateBroadcast: StateBroadcastData*
  - Platoon_serialise / Platoon__NV_serialise: PosRotPair* (arg 4)
  - Platoon_getUnloadedPlatoon: UnloadedPlatoon*
  - Platoon_getPatrolInfo: PatrolInfo*
  - Platoon_getRoamingMapArea / Platoon_setRoamingMapArea: AreaBiomeGroup*
*/

static int Platoon_chooseNewHome(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    hand result = b->chooseNewHome();
    handBinding::push(L, result);
    return 1;
}

static int Platoon_getCurrentTownLocation(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    TownBase* result = b->getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

static int Platoon__NV_getCurrentTownLocation(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    TownBase* result = b->_NV_getCurrentTownLocation();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

static int Platoon_hasCampaign(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    CampaignInstance* res = b->hasCampaign();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_iBuyStolenGoods(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Item* what = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    bool res = b->iBuyStolenGoods(what);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int Platoon_setFaction(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->setFaction(f);
    return 0;
}

static int Platoon__NV_setFaction(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Faction* f = checkObject<Faction>(L, 2, FactionBinding::getMetatableName());
    b->_NV_setFaction(f);
    return 0;
}

static int Platoon_canTakeRefugees(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Platoon* who = checkObject<Platoon>(L, 2, PlatoonBinding::getMetatableName());
    bool res = b->canTakeRefugees(who);
    lua_pushboolean(L, res ? 1 : 0);
    return 1;
}

static int Platoon_isUnique(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    UniquePlatoon* res = b->isUnique();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon__NV_isUnique(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    UniquePlatoon* res = b->_NV_isUnique();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_getBlackboard(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Blackboard* res = b->getBlackboard();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_getStateBroadcast(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    StateBroadcastData* res = b->getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon__NV_getStateBroadcast(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    StateBroadcastData* res = b->_NV_getStateBroadcast();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_serialiseEverything(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* res = b->serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

static int Platoon__NV_serialiseEverything(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameDataContainer* dataContainer = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    bool levelEditor = lua_toboolean(L, 3) != 0;
    GameData* res = b->_NV_serialiseEverything(dataContainer, levelEditor);
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

static int Platoon_loadStateData(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->loadStateData(state);
    return 0;
}

static int Platoon__NV_loadStateData(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameData* state = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    b->_NV_loadStateData(state);
    return 0;
}

static int Platoon_serialise(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = b->serialise(container, refList, offsetPosToSubtract);
    GameSaveState* copy = new GameSaveState(res);
    return pushObject<GameSaveState>(L, copy, GameSaveStateBinding::getMetatableName());
}

static int Platoon__NV_serialise(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offsetPosToSubtract = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState res = b->_NV_serialise(container, refList, offsetPosToSubtract);
    GameSaveState* copy = new GameSaveState(res);
    return pushObject<GameSaveState>(L, copy, GameSaveStateBinding::getMetatableName());
}

static int Platoon_loadFromSerialise(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    b->loadFromSerialise(state);
    return 0;
}

static int Platoon__NV_loadFromSerialise(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    b->_NV_loadFromSerialise(state);
    return 0;
}

static int Platoon_reprocessTask(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    b->reprocessTask(t);
    return 0;
}

static int Platoon_taskIsComplete(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    Tasker* t = checkObject<Tasker>(L, 2, TaskerBinding::getMetatableName());
    b->taskIsComplete(t);
    return 0;
}

static int Platoon_deactivate(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    GameDataContainer* forceCharacterStates = nullptr;
    if (lua_isuserdata(L, 2)) {
        forceCharacterStates = (GameDataContainer*)lua_touserdata(L, 2);
    } else if (!lua_isnil(L, 2)) {
        forceCharacterStates = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    }
    b->deactivate(forceCharacterStates);
    return 0;
}

static int Platoon_getActivePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    ActivePlatoon* result = b->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

static int Platoon_getUnloadedPlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    UnloadedPlatoon* res = b->getUnloadedPlatoon();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_getPatrolInfo(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    PatrolInfo* res = b->getPatrolInfo();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_getRoamingMapArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    AreaBiomeGroup* res = b->getRoamingMapArea();
    if (res) lua_pushlightuserdata(L, res);
    else lua_pushnil(L);
    return 1;
}

static int Platoon_setRoamingMapArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    AreaBiomeGroup* maparea = (AreaBiomeGroup*)lua_touserdata(L, 2);
    b->setRoamingMapArea(maparea);
    return 0;
}

static int Platoon_getSquadLeader_theRealOne(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    const hand& result = b->getSquadLeader_theRealOne();
    handBinding::push(L, result);
    return 1;
}

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

void PlatoonBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PlatoonBinding::gc },
        { "__tostring", PlatoonBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", PlatoonBinding::_DESTRUCTOR },
        { "setCharacterCount", PlatoonBinding::setCharacterCount },
        { "isUnconcious", PlatoonBinding::isUnconcious },
        { "_NV_isUnconcious", PlatoonBinding::_NV_isUnconcious },
        { "getSquadType", PlatoonBinding::getSquadType },
        { "setSquadType", PlatoonBinding::setSquadType },
        { "iBuyIllegalGoods", PlatoonBinding::iBuyIllegalGoods },
        { "getPlatoonStringID", PlatoonBinding::getPlatoonStringID },
        { "getDataType", PlatoonBinding::getDataType },
        { "_NV_getDataType", PlatoonBinding::_NV_getDataType },
        { "erasePlatoonFile", PlatoonBinding::erasePlatoonFile },
        { "showDebugMarker", PlatoonBinding::showDebugMarker },
        { "setDataFilename", PlatoonBinding::setDataFilename },
        { "isIntact", PlatoonBinding::isIntact },
        { "notifyMissionEnded", PlatoonBinding::notifyMissionEnded },
        { "_NV_notifyMissionEnded", PlatoonBinding::_NV_notifyMissionEnded },
        { "activate", PlatoonBinding::activate },
        { "declareDead", PlatoonBinding::declareDead },
        { "undeclareDead", PlatoonBinding::undeclareDead },
        { "isFullyLoaded", PlatoonBinding::isFullyLoaded },
        { "update", PlatoonBinding::update },
        { "_NV_update", PlatoonBinding::_NV_update },
        { "periodicUpdate_active", PlatoonBinding::periodicUpdate_active },
        { "_NV_periodicUpdate_active", PlatoonBinding::_NV_periodicUpdate_active },
        { "periodicUpdate_unloaded", PlatoonBinding::periodicUpdate_unloaded },
        { "_NV_periodicUpdate_unloaded", PlatoonBinding::_NV_periodicUpdate_unloaded },
        { "setupPatrolSettings", PlatoonBinding::setupPatrolSettings },
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
        { "chooseNewHome", Platoon_chooseNewHome },
        { "getCurrentTownLocation", Platoon_getCurrentTownLocation },
        { "_NV_getCurrentTownLocation", Platoon__NV_getCurrentTownLocation },
        { "hasCampaign", Platoon_hasCampaign },
        { "iBuyStolenGoods", Platoon_iBuyStolenGoods },
        { "setFaction", Platoon_setFaction },
        { "_NV_setFaction", Platoon__NV_setFaction },
        { "canTakeRefugees", Platoon_canTakeRefugees },
        { "isUnique", Platoon_isUnique },
        { "_NV_isUnique", Platoon__NV_isUnique },
        { "getBlackboard", Platoon_getBlackboard },
        { "getStateBroadcast", Platoon_getStateBroadcast },
        { "_NV_getStateBroadcast", Platoon__NV_getStateBroadcast },
        { "serialiseEverything", Platoon_serialiseEverything },
        { "_NV_serialiseEverything", Platoon__NV_serialiseEverything },
        { "loadStateData", Platoon_loadStateData },
        { "_NV_loadStateData", Platoon__NV_loadStateData },
        { "serialise", Platoon_serialise },
        { "_NV_serialise", Platoon__NV_serialise },
        { "loadFromSerialise", Platoon_loadFromSerialise },
        { "_NV_loadFromSerialise", Platoon__NV_loadFromSerialise },
        { "reprocessTask", Platoon_reprocessTask },
        { "taskIsComplete", Platoon_taskIsComplete },
        { "deactivate", Platoon_deactivate },
        { "getActivePlatoon", Platoon_getActivePlatoon },
        { "getUnloadedPlatoon", Platoon_getUnloadedPlatoon },
        { "getPatrolInfo", Platoon_getPatrolInfo },
        { "getRoamingMapArea", Platoon_getRoamingMapArea },
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
    lua_pushcfunction(L, Platoon_get_stringID);
    lua_setfield(L, -2, "stringID");
    lua_pushcfunction(L, Platoon_get__characterCountCurrent);
    lua_setfield(L, -2, "_characterCountCurrent");
    lua_pushcfunction(L, Platoon_get__characterCountOriginal);
    lua_setfield(L, -2, "_characterCountOriginal");
    lua_pushcfunction(L, Platoon_get_squadType);
    lua_setfield(L, -2, "squadType");
    lua_pushcfunction(L, Platoon_get_hasUniques);
    lua_setfield(L, -2, "hasUniques");
    lua_pushcfunction(L, Platoon_get_speedOverride);
    lua_setfield(L, -2, "speedOverride");
    lua_pushcfunction(L, Platoon_get_isSeparatedSquad);
    lua_setfield(L, -2, "isSeparatedSquad");
    lua_pushcfunction(L, Platoon_get_canRefresh);
    lua_setfield(L, -2, "canRefresh");
    lua_pushcfunction(L, Platoon_get_regenerates);
    lua_setfield(L, -2, "regenerates");
    lua_pushcfunction(L, Platoon_get_myBaseHomeTownData);
    lua_setfield(L, -2, "myBaseHomeTownData");
    lua_pushcfunction(L, Platoon_get_priceMultWhenITrade);
    lua_setfield(L, -2, "priceMultWhenITrade");
    lua_pushcfunction(L, Platoon_get__iBuyStolenGoods);
    lua_setfield(L, -2, "_iBuyStolenGoods");
    lua_pushcfunction(L, Platoon_get__iBuyIllegalGoods);
    lua_setfield(L, -2, "_iBuyIllegalGoods");
    lua_pushcfunction(L, Platoon_get_locatorModel);
    lua_setfield(L, -2, "locatorModel");
    lua_pushcfunction(L, Platoon_get_blackboard);
    lua_setfield(L, -2, "blackboard");
    lua_pushcfunction(L, Platoon_get__isIntact);
    lua_setfield(L, -2, "_isIntact");
    lua_pushcfunction(L, Platoon_get_squadTemplate);
    lua_setfield(L, -2, "squadTemplate");
    lua_pushcfunction(L, Platoon_get_malnourishedLevel);
    lua_setfield(L, -2, "malnourishedLevel");
    lua_pushcfunction(L, Platoon_get_hasNeverBeenActivated);
    lua_setfield(L, -2, "hasNeverBeenActivated");
    lua_pushcfunction(L, Platoon_get__persistentSquad);
    lua_setfield(L, -2, "_persistentSquad");
    lua_pushcfunction(L, Platoon_get_isResidentSquad);
    lua_setfield(L, -2, "isResidentSquad");
    lua_pushcfunction(L, Platoon_get_messageOnActivation);
    lua_setfield(L, -2, "messageOnActivation");
    lua_pushcfunction(L, Platoon_get_currentSpawnArea);
    lua_setfield(L, -2, "currentSpawnArea");
    lua_pushcfunction(L, Platoon_get_squadleader);
    lua_setfield(L, -2, "squadleader");
    lua_pushcfunction(L, Platoon_get_ownerships);
    lua_setfield(L, -2, "ownerships");
    lua_pushcfunction(L, Platoon_get_activePlatoon);
    lua_setfield(L, -2, "activePlatoon");
    lua_pushcfunction(L, Platoon_get_unloadedPlatoon);
    lua_setfield(L, -2, "unloadedPlatoon");
    lua_pushcfunction(L, Platoon_get_patrolSettings);
    lua_setfield(L, -2, "patrolSettings");
    lua_pushcfunction(L, Platoon_get_isDead);
    lua_setfield(L, -2, "isDead");
    lua_pushcfunction(L, Platoon_get_imprisoned);
    lua_setfield(L, -2, "imprisoned");
    lua_pushcfunction(L, Platoon_get_index);
    lua_setfield(L, -2, "index");
    lua_pushcfunction(L, Platoon_get_traderInventoryRefreshTime);
    lua_setfield(L, -2, "traderInventoryRefreshTime");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, Platoon_set_stringID);
    lua_setfield(L, -2, "stringID");
    lua_pushcfunction(L, Platoon_set__characterCountCurrent);
    lua_setfield(L, -2, "_characterCountCurrent");
    lua_pushcfunction(L, Platoon_set__characterCountOriginal);
    lua_setfield(L, -2, "_characterCountOriginal");
    lua_pushcfunction(L, Platoon_set_squadType);
    lua_setfield(L, -2, "squadType");
    lua_pushcfunction(L, Platoon_set_hasUniques);
    lua_setfield(L, -2, "hasUniques");
    lua_pushcfunction(L, Platoon_set_speedOverride);
    lua_setfield(L, -2, "speedOverride");
    lua_pushcfunction(L, Platoon_set_isSeparatedSquad);
    lua_setfield(L, -2, "isSeparatedSquad");
    lua_pushcfunction(L, Platoon_set_canRefresh);
    lua_setfield(L, -2, "canRefresh");
    lua_pushcfunction(L, Platoon_set_regenerates);
    lua_setfield(L, -2, "regenerates");
    lua_pushcfunction(L, Platoon_set_myBaseHomeTownData);
    lua_setfield(L, -2, "myBaseHomeTownData");
    lua_pushcfunction(L, Platoon_set_priceMultWhenITrade);
    lua_setfield(L, -2, "priceMultWhenITrade");
    lua_pushcfunction(L, Platoon_set__iBuyStolenGoods);
    lua_setfield(L, -2, "_iBuyStolenGoods");
    lua_pushcfunction(L, Platoon_set__iBuyIllegalGoods);
    lua_setfield(L, -2, "_iBuyIllegalGoods");
    lua_pushcfunction(L, Platoon_set_locatorModel);
    lua_setfield(L, -2, "locatorModel");
    lua_pushcfunction(L, Platoon_set_blackboard);
    lua_setfield(L, -2, "blackboard");
    lua_pushcfunction(L, Platoon_set__isIntact);
    lua_setfield(L, -2, "_isIntact");
    lua_pushcfunction(L, Platoon_set_squadTemplate);
    lua_setfield(L, -2, "squadTemplate");
    lua_pushcfunction(L, Platoon_set_malnourishedLevel);
    lua_setfield(L, -2, "malnourishedLevel");
    lua_pushcfunction(L, Platoon_set_hasNeverBeenActivated);
    lua_setfield(L, -2, "hasNeverBeenActivated");
    lua_pushcfunction(L, Platoon_set__persistentSquad);
    lua_setfield(L, -2, "_persistentSquad");
    lua_pushcfunction(L, Platoon_set_isResidentSquad);
    lua_setfield(L, -2, "isResidentSquad");
    lua_pushcfunction(L, Platoon_set_messageOnActivation);
    lua_setfield(L, -2, "messageOnActivation");
    lua_pushcfunction(L, Platoon_set_currentSpawnArea);
    lua_setfield(L, -2, "currentSpawnArea");
    lua_pushcfunction(L, Platoon_set_squadleader);
    lua_setfield(L, -2, "squadleader");
    lua_pushcfunction(L, Platoon_set_ownerships);
    lua_setfield(L, -2, "ownerships");
    lua_pushcfunction(L, Platoon_set_activePlatoon);
    lua_setfield(L, -2, "activePlatoon");
    lua_pushcfunction(L, Platoon_set_unloadedPlatoon);
    lua_setfield(L, -2, "unloadedPlatoon");
    lua_pushcfunction(L, Platoon_set_patrolSettings);
    lua_setfield(L, -2, "patrolSettings");
    lua_pushcfunction(L, Platoon_set_isDead);
    lua_setfield(L, -2, "isDead");
    lua_pushcfunction(L, Platoon_set_imprisoned);
    lua_setfield(L, -2, "imprisoned");
    lua_pushcfunction(L, Platoon_set_index);
    lua_setfield(L, -2, "index");
    lua_pushcfunction(L, Platoon_set_traderInventoryRefreshTime);
    lua_setfield(L, -2, "traderInventoryRefreshTime");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    LektorPtrBinding<Platoon*>::registerBinding(L, "lektor<Platoon*>", PlatoonBinding::getMetatableName());
}

} // namespace KenshiLua
