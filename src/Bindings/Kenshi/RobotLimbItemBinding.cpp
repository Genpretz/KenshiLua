#include "pch.h"
#include "kenshi/Gear.h"
#include "Bindings/Kenshi/RobotLimbItemBinding.h"
#include "Bindings/Kenshi/GearBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/EnumBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/OgreVectorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(RobotLimbItem, statMults) == 0x228, "RobotLimbItem::statMults offset mismatch");
static_assert(offsetof(RobotLimbItem, maxHP) == 0x268, "RobotLimbItem::maxHP offset mismatch");
static_assert(offsetof(RobotLimbItem, currentDamage) == 0x26C, "RobotLimbItem::currentDamage offset mismatch");
static_assert(offsetof(RobotLimbItem, wearDamage) == 0x270, "RobotLimbItem::wearDamage offset mismatch");
static_assert(offsetof(RobotLimbItem, stunDamage) == 0x274, "RobotLimbItem::stunDamage offset mismatch");
static_assert(offsetof(RobotLimbItem, unarmedDamage) == 0x278, "RobotLimbItem::unarmedDamage offset mismatch");

static RobotLimbItem* getInstance(lua_State* L, int idx)
{
    return checkObject<RobotLimbItem>(L, idx, RobotLimbItemBinding::getMetatableName());
}

static int RobotLimbItem_get_statMults(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    return pushObject<ogre_unordered_map<StatsEnumerated, float>::type>(
        L, &instance->statMults, OgreUnorderedMapBinding<StatsEnumerated, float>::getMetatableName());
}

static int RobotLimbItem_set_statMults(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    auto* val = OgreUnorderedMapBinding<StatsEnumerated, float>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'statMults' must be ogre_unordered_map<StatsEnumerated, float>");
    instance->statMults = *val;
    return 0;
}

static int RobotLimbItem_get_maxHP(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    lua_pushnumber(L, instance->maxHP);
    return 1;
}

static int RobotLimbItem_set_maxHP(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    instance->maxHP = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RobotLimbItem_get_currentDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    lua_pushnumber(L, instance->currentDamage);
    return 1;
}

static int RobotLimbItem_set_currentDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    instance->currentDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RobotLimbItem_get_wearDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    lua_pushnumber(L, instance->wearDamage);
    return 1;
}

static int RobotLimbItem_set_wearDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    instance->wearDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RobotLimbItem_get_stunDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    lua_pushnumber(L, instance->stunDamage);
    return 1;
}

static int RobotLimbItem_set_stunDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    instance->stunDamage = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RobotLimbItem_get_unarmedDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    lua_pushinteger(L, instance->unarmedDamage);
    return 1;
}

static int RobotLimbItem_set_unarmedDamage(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    instance->unarmedDamage = (int)luaL_checkinteger(L, 2);
    return 0;
}

int RobotLimbItemBinding::getStatMult(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    StatsEnumerated stat = (StatsEnumerated)luaL_checkinteger(L, 2);
    float result = instance->getStatMult(stat);
    lua_pushnumber(L, result);
    return 1;
}

int RobotLimbItemBinding::_serialise(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RobotLimbItemBinding::_NV__serialise(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType type = (itemType)luaL_checkinteger(L, 3);
    GameData* result = instance->_NV__serialise(container, type);
    return pushObject<GameData>(L, result, GameDataBinding::getMetatableName());
}

int RobotLimbItemBinding::_loadFromSerialise(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int RobotLimbItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int RobotLimbItemBinding::getCraftTime(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    float result = instance->getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int RobotLimbItemBinding::_NV_getCraftTime(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    float result = instance->_NV_getCraftTime();
    lua_pushnumber(L, result);
    return 1;
}

int RobotLimbItemBinding::getTooltipData1(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    auto* lines = OgreVectorValueBinding<StringPair>::getInstance(L, 2);
    if (!lines) return luaL_error(L, "Argument 2 to getTooltipData1 must be ogre_vector<StringPair>");
    instance->getTooltipData1(*lines);
    return 0;
}

int RobotLimbItemBinding::_NV_getTooltipData1(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    auto* lines = OgreVectorValueBinding<StringPair>::getInstance(L, 2);
    if (!lines) return luaL_error(L, "Argument 2 to _NV_getTooltipData1 must be ogre_vector<StringPair>");
    instance->_NV_getTooltipData1(*lines);
    return 0;
}

int RobotLimbItemBinding::getTooltipData2(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    auto* lines = OgreVectorValueBinding<StringPair>::getInstance(L, 2);
    if (!lines) return luaL_error(L, "Argument 2 to getTooltipData2 must be ogre_vector<StringPair>");
    instance->getTooltipData2(*lines);
    return 0;
}

int RobotLimbItemBinding::_NV_getTooltipData2(lua_State* L)
{
    RobotLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RobotLimbItem is nil");
    auto* lines = OgreVectorValueBinding<StringPair>::getInstance(L, 2);
    if (!lines) return luaL_error(L, "Argument 2 to _NV_getTooltipData2 must be ogre_vector<StringPair>");
    instance->_NV_getTooltipData2(*lines);
    return 0;
}

int RobotLimbItemBinding::gc(lua_State* L)
{
    return noopGc(L);
}

int RobotLimbItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RobotLimbItem object");
    return 1;
}

void RobotLimbItemBinding::registerBinding(lua_State* L)
{
    OgreUnorderedMapBinding<StatsEnumerated, float>::registerBinding(L, "ogre_unordered_map<StatsEnumerated, float>", nullptr, nullptr);

    static const luaL_Reg meta[] = {
        { "__gc",       RobotLimbItemBinding::gc },
        { "__tostring", RobotLimbItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getStatMult", RobotLimbItemBinding::getStatMult },
        { "_serialise", RobotLimbItemBinding::_serialise },
        { "_NV__serialise", RobotLimbItemBinding::_NV__serialise },
        { "_loadFromSerialise", RobotLimbItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", RobotLimbItemBinding::_NV__loadFromSerialise },
        { "getCraftTime", RobotLimbItemBinding::getCraftTime },
        { "_NV_getCraftTime", RobotLimbItemBinding::_NV_getCraftTime },
        { "getTooltipData1", RobotLimbItemBinding::getTooltipData1 },
        { "_NV_getTooltipData1", RobotLimbItemBinding::_NV_getTooltipData1 },
        { "getTooltipData2", RobotLimbItemBinding::getTooltipData2 },
        { "_NV_getTooltipData2", RobotLimbItemBinding::_NV_getTooltipData2 },
        { 0, 0 }
    };

    registerClass(
        L, 
        RobotLimbItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    // Setup setters/getters tables
    luaL_getmetatable(L, RobotLimbItemBinding::getMetatableName());
    lua_newtable(L); // getters
    registerGetter(L, "statMults", RobotLimbItem_get_statMults);
    registerGetter(L, "maxHP", RobotLimbItem_get_maxHP);
    registerGetter(L, "currentDamage", RobotLimbItem_get_currentDamage);
    registerGetter(L, "wearDamage", RobotLimbItem_get_wearDamage);
    registerGetter(L, "stunDamage", RobotLimbItem_get_stunDamage);
    registerGetter(L, "unarmedDamage", RobotLimbItem_get_unarmedDamage);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // setters
    registerSetter(L, "statMults", RobotLimbItem_set_statMults);
    registerSetter(L, "maxHP", RobotLimbItem_set_maxHP);
    registerSetter(L, "currentDamage", RobotLimbItem_set_currentDamage);
    registerSetter(L, "wearDamage", RobotLimbItem_set_wearDamage);
    registerSetter(L, "stunDamage", RobotLimbItem_set_stunDamage);
    registerSetter(L, "unarmedDamage", RobotLimbItem_set_unarmedDamage);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
