#include "pch.h"
<<<<<<< HEAD:src/Bindings/World/PlatoonBinding.cpp
#include "Bindings/World/PlatoonBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/World/FactionBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Bindings/Utility/HandBinding.h"
=======
#include "kenshi\Platoon.h"
#include "PlatoonBinding.h"
#include "OwnershipsBinding.h"
>>>>>>> main:src/Bindings/PlatoonBinding.cpp
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/OwnershipsBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/TownBaseBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Templates/LektorBinding.h"

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
    // TODO: Unsupported type for hasUniques (YesNoMaybe)
    return luaL_error(L, "Unsupported property 'hasUniques' (type: YesNoMaybe)");
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
    // TODO: Unsupported type for locatorModel (Ogre::Entity*)
    return luaL_error(L, "Unsupported property 'locatorModel' (type: Ogre::Entity*)");
}

static int Platoon_get_blackboard(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    // TODO: Unsupported type for blackboard (Blackboard*)
    return luaL_error(L, "Unsupported property 'blackboard' (type: Blackboard*)");
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
    // TODO: Unsupported type for messageOnActivation (PlatoonCreationMessage)
    return luaL_error(L, "Unsupported property 'messageOnActivation' (type: PlatoonCreationMessage)");
}

static int Platoon_get_currentSpawnArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    // TODO: Unsupported type for currentSpawnArea (AreaSector*)
    return luaL_error(L, "Unsupported property 'currentSpawnArea' (type: AreaSector*)");
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
    // TODO: Unsupported type for ownerships (Ownerships)
    return luaL_error(L, "Unsupported property 'ownerships' (type: Ownerships)");
}

static int Platoon_get_activePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    // TODO: Unsupported type for activePlatoon (ActivePlatoon*)
    return luaL_error(L, "Unsupported property 'activePlatoon' (type: ActivePlatoon*)");
}

static int Platoon_get_unloadedPlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    // TODO: Unsupported type for unloadedPlatoon (UnloadedPlatoon*)
    return luaL_error(L, "Unsupported property 'unloadedPlatoon' (type: UnloadedPlatoon*)");
}

static int Platoon_get_patrolSettings(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    // TODO: Unsupported type for patrolSettings (PatrolInfo*)
    return luaL_error(L, "Unsupported property 'patrolSettings' (type: PatrolInfo*)");
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
    // TODO: Unsupported type for traderInventoryRefreshTime (TimeOfDay)
    return luaL_error(L, "Unsupported property 'traderInventoryRefreshTime' (type: TimeOfDay)");
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
    return luaL_error(L, "Read-only or unsupported setter type for hasUniques");
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
    return luaL_error(L, "Read-only or unsupported setter type for myBaseHomeTownData");
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
    return luaL_error(L, "Read-only or unsupported setter type for locatorModel");
}

static int Platoon_set_blackboard(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for blackboard");
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
    return luaL_error(L, "Read-only or unsupported setter type for squadTemplate");
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
    return luaL_error(L, "Read-only or unsupported setter type for messageOnActivation");
}

static int Platoon_set_currentSpawnArea(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for currentSpawnArea");
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
    return luaL_error(L, "Read-only or unsupported setter type for ownerships");
}

static int Platoon_set_activePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for activePlatoon");
}

static int Platoon_set_unloadedPlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for unloadedPlatoon");
}

static int Platoon_set_patrolSettings(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    return luaL_error(L, "Read-only or unsupported setter type for patrolSettings");
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
    return luaL_error(L, "Read-only or unsupported setter type for traderInventoryRefreshTime");
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
  line 108: Platoon* _CONSTRUCTOR(...) - unsupported arg type
  line 121: hand chooseNewHome(...) - unsupported return type
  line 126: TownBase* getCurrentTownLocation(...) - unsupported return type
  line 127: TownBase* _NV_getCurrentTownLocation(...) - unsupported return type
  line 128: CampaignInstance* hasCampaign(...) - unsupported return type
  line 132: bool iBuyStolenGoods(...) - unsupported arg type
  line 134: void setFaction(...) - unsupported arg type
  line 135: void _NV_setFaction(...) - unsupported arg type
  line 136: bool canTakeRefugees(...) - unsupported arg type
  line 139: UniquePlatoon* isUnique(...) - unsupported return type
  line 140: UniquePlatoon* _NV_isUnique(...) - unsupported return type
  line 142: Blackboard* getBlackboard(...) - unsupported return type
  line 148: StateBroadcastData* getStateBroadcast(...) - unsupported return type
  line 149: StateBroadcastData* _NV_getStateBroadcast(...) - unsupported return type
  line 150: GameData* serialiseEverything(...) - unsupported arg type
  line 151: GameData* _NV_serialiseEverything(...) - unsupported arg type
  line 152: void loadStateData(...) - unsupported arg type
  line 153: void _NV_loadStateData(...) - unsupported arg type
  line 154: GameSaveState serialise(...) - unsupported return type
  line 155: GameSaveState _NV_serialise(...) - unsupported return type
  line 156: void loadFromSerialise(...) - unsupported arg type
  line 157: void _NV_loadFromSerialise(...) - unsupported arg type
  line 158: void reprocessTask(...) - unsupported arg type
  line 159: void taskIsComplete(...) - unsupported arg type
  line 167: void deactivate(...) - unsupported arg type
  line 171: ActivePlatoon* getActivePlatoon(...) - unsupported return type
  line 172: UnloadedPlatoon* getUnloadedPlatoon(...) - unsupported return type
  line 180: PatrolInfo* getPatrolInfo(...) - unsupported return type
  line 181: AreaBiomeGroup* getRoamingMapArea(...) - unsupported return type
  line 182: void setRoamingMapArea(...) - unsupported arg type
  line 194: const hand& getSquadLeader_theRealOne(...) - reference return type
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

static int Platoon_getActivePlatoon(lua_State* L)
{
    Platoon* b = getB(L, 1);
    if (!b) return luaL_error(L, "Platoon is nil");
    ActivePlatoon* result = b->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
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
        { "setFaction", Platoon_setFaction },
        { "_NV_setFaction", Platoon__NV_setFaction },
        { "getActivePlatoon", Platoon_getActivePlatoon },
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