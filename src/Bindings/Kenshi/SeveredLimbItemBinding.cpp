#include "pch.h"
#include "kenshi/Item.h"
#include "SeveredLimbItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/Util/TimeOfDayBinding.h"

namespace KenshiLua
{

static_assert(offsetof(SeveredLimbItem, limbScale) == 0x1E8, "SeveredLimbItem::limbScale offset mismatch");
static_assert(offsetof(SeveredLimbItem, skinTone) == 0x1F4, "SeveredLimbItem::skinTone offset mismatch");
static_assert(offsetof(SeveredLimbItem, blood) == 0x204, "SeveredLimbItem::blood offset mismatch");
static_assert(offsetof(SeveredLimbItem, impulse) == 0x214, "SeveredLimbItem::impulse offset mismatch");
static_assert(offsetof(SeveredLimbItem, timeout) == 0x220, "SeveredLimbItem::timeout offset mismatch");

static SeveredLimbItem* getInstance(lua_State* L, int idx)
{
    return checkObject<SeveredLimbItem>(L, idx, SeveredLimbItemBinding::getMetatableName());
}

static int SeveredLimbItem_get_limbScale(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    pushVector3(L, instance->limbScale);
    return 1;
}

static int SeveredLimbItem_set_limbScale(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    readVector3(L, 2, instance->limbScale);
    return 0;
}

static int SeveredLimbItem_get_skinTone(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    pushVector4(L, instance->skinTone);
    return 1;
}

static int SeveredLimbItem_set_skinTone(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    readVector4(L, 2, instance->skinTone);
    return 0;
}

static int SeveredLimbItem_get_blood(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    pushColourValue(L, instance->blood);
    return 1;
}

static int SeveredLimbItem_set_blood(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    readColourValue(L, 2, instance->blood);
    return 0;
}

static int SeveredLimbItem_get_impulse(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    pushVector3(L, instance->impulse);
    return 1;
}

static int SeveredLimbItem_set_impulse(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    readVector3(L, 2, instance->impulse);
    return 0;
}

static int SeveredLimbItem_get_timeout(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    return pushObject<TimeOfDay>(L, &instance->timeout, TimeOfDayBinding::getMetatableName());
}

static int SeveredLimbItem_set_timeout(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    TimeOfDay* t = checkObject<TimeOfDay>(L, 2, TimeOfDayBinding::getMetatableName());
    if (t) instance->timeout = *t;
    return 0;
}

int SeveredLimbItemBinding::setupFromCharacter(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    Character* c = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    int limb = (int)luaL_checkinteger(L, 3);
    Ogre::Vector3 force;
    if (!readVector3(L, 4, force)) return luaL_error(L, "Argument 4 to setupFromCharacter must be Vector3");
    instance->setupFromCharacter(c, limb, force);
    return 0;
}

int SeveredLimbItemBinding::_serialise(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType typ = (itemType)luaL_checkinteger(L, 3);
    GameData* res = instance->_serialise(container, typ);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int SeveredLimbItemBinding::_NV__serialise(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    itemType typ = (itemType)luaL_checkinteger(L, 3);
    GameData* res = instance->_NV__serialise(container, typ);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<GameData>(L, res, GameDataBinding::getMetatableName());
}

int SeveredLimbItemBinding::_loadFromSerialise(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_loadFromSerialise(container, state);
    return 0;
}

int SeveredLimbItemBinding::_NV__loadFromSerialise(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* state = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->_NV__loadFromSerialise(container, state);
    return 0;
}

int SeveredLimbItemBinding::getTimeout(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    TimeOfDay res = instance->getTimeout();
    return pushValue<TimeOfDay>(L, res, TimeOfDayBinding::getMetatableName());
}

int SeveredLimbItemBinding::_NV_getTimeout(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    TimeOfDay res = instance->_NV_getTimeout();
    return pushValue<TimeOfDay>(L, res, TimeOfDayBinding::getMetatableName());
}

int SeveredLimbItemBinding::destroyPhysical(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    instance->destroyPhysical();
    return 0;
}

int SeveredLimbItemBinding::_NV_destroyPhysical(lua_State* L)
{
    SeveredLimbItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "SeveredLimbItem is nil");
    instance->_NV_destroyPhysical();
    return 0;
}

int SeveredLimbItemBinding::gc(lua_State* L)
{
    return 0;
}

int SeveredLimbItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.SeveredLimbItem object");
    return 1;
}

void SeveredLimbItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       SeveredLimbItemBinding::gc },
        { "__tostring", SeveredLimbItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupFromCharacter", SeveredLimbItemBinding::setupFromCharacter },
        { "_serialise", SeveredLimbItemBinding::_serialise },
        { "_NV__serialise", SeveredLimbItemBinding::_NV__serialise },
        { "_loadFromSerialise", SeveredLimbItemBinding::_loadFromSerialise },
        { "_NV__loadFromSerialise", SeveredLimbItemBinding::_NV__loadFromSerialise },
        { "getTimeout", SeveredLimbItemBinding::getTimeout },
        { "_NV_getTimeout", SeveredLimbItemBinding::_NV_getTimeout },
        { "destroyPhysical", SeveredLimbItemBinding::destroyPhysical },
        { "_NV_destroyPhysical", SeveredLimbItemBinding::_NV_destroyPhysical },
        { 0, 0 }
    };

    registerClass(
        L, 
        SeveredLimbItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, SeveredLimbItemBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "limbScale", SeveredLimbItem_get_limbScale);
    registerGetter(L, "skinTone", SeveredLimbItem_get_skinTone);
    registerGetter(L, "blood", SeveredLimbItem_get_blood);
    registerGetter(L, "impulse", SeveredLimbItem_get_impulse);
    registerGetter(L, "timeout", SeveredLimbItem_get_timeout);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "limbScale", SeveredLimbItem_set_limbScale);
    registerSetter(L, "skinTone", SeveredLimbItem_set_skinTone);
    registerSetter(L, "blood", SeveredLimbItem_set_blood);
    registerSetter(L, "impulse", SeveredLimbItem_set_impulse);
    registerSetter(L, "timeout", SeveredLimbItem_set_timeout);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
