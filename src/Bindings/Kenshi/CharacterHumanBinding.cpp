#include "pch.h"
#include "kenshi\CharacterHuman.h"
#include <kenshi/GameSaveState.h>
#include "CharacterHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/ActivePlatoonBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/CrossbowBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataContainerBinding.h"
#include "Bindings/Kenshi/GameDataCopyStandaloneBinding.h"
#include "Bindings/Kenshi/GameSaveStateBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/WeaponBinding.h"
#include "kenshi/Gear.h"

namespace KenshiLua
{

static CharacterHuman* getInstance(lua_State* L, int idx)
{
    return checkObject<CharacterHuman>(L, idx, CharacterHumanBinding::getMetatableName());
}

// --- Getters for CharacterHuman ---
static int CharacterHuman_get_weaponInHands(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    return pushObject<Weapon>(L, instance->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterHuman_get_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    lua_pushstring(L, instance->weaponInHandsSheathLocation.c_str());
    return 1;
}

// --- Setters for CharacterHuman ---
static int CharacterHuman_set_weaponInHands(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->weaponInHands = lua_isnoneornil(L, 2) ? nullptr : checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    return 0;
}

static int CharacterHuman_set_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->weaponInHandsSheathLocation = luaL_checkstring(L, 2);
    return 0;
}

int CharacterHumanBinding::isHuman(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    CharacterHuman* result = instance->isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_isHuman(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    CharacterHuman* result = instance->_NV_isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_drawWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    const char* lastSection = luaL_checkstring(L, 3);
    bool result = instance->_NV_drawWeapon(item, lastSection);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->_NV_sheatheWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    Weapon* result = instance->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    Weapon* result = instance->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getRangedWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    Crossbow* result = instance->_NV_getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_loadFromSerialise(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int CharacterHumanBinding::_NV_giveBirth(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    GameDataCopyStandalone* _appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 _pos;
    checkVector3(L, 3, _pos);
    Ogre::Quaternion _rot;
    checkQuaternion(L, 4, _rot);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->_NV_giveBirth(_appearance, _pos, _rot, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_setupInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_validateInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->_NV_validateInventorySections();
    return 0;
}

int CharacterHumanBinding::_NV_setupAudio(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->_NV_setupAudio();
    return 0;
}

int CharacterHumanBinding::shaveHead(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    bool on = lua_toboolean(L, 2) != 0;
    instance->shaveHead(on);
    return 0;
}

int CharacterHumanBinding::_NV_isHeadShaven(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    bool result = instance->_NV_isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->_NV_createAnimationClass();
    return 0;
}

int CharacterHumanBinding::dropItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::_NV_dropItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::dropWeaponInHands(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->dropWeaponInHands();
    return 0;
}

int CharacterHumanBinding::dropWeaponInHandsFake(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->dropWeaponInHandsFake();
    return 0;
}

int CharacterHumanBinding::_NV_unequipItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    const char* section = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(section, item);
    return 0;
}

int CharacterHumanBinding::_NV_weatherUpdate(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_weatherUpdate(time);
    return 0;
}

int CharacterHumanBinding::leaveSheathEquipped(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    const char* section = luaL_checkstring(L, 2);
    int ypos = (int)luaL_checkinteger(L, 3);
    instance->leaveSheathEquipped(section, ypos);
    return 0;
}

int CharacterHumanBinding::_NV_postRagdollCallback(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->_NV_postRagdollCallback(on, part);
    return 0;
}

int CharacterHumanBinding::_NV_reCalculateNaturalWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    instance->_NV_reCalculateNaturalWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_serialise(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);
    GameSaveState result = instance->_NV_serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - CharacterHumanBinding::_NV_serialise: PosRotPair* (unbound pointer)
*/

int CharacterHumanBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterHumanBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterHuman object");
    return 1;
}

void CharacterHumanBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterHumanBinding::gc },
        { "__tostring", CharacterHumanBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isHuman", CharacterHumanBinding::isHuman },
        { "_NV_isHuman", CharacterHumanBinding::_NV_isHuman },
        { "_NV_drawWeapon", CharacterHumanBinding::_NV_drawWeapon },
        { "_NV_sheatheWeapon", CharacterHumanBinding::_NV_sheatheWeapon },
        { "_NV_getCurrentWeapon", CharacterHumanBinding::_NV_getCurrentWeapon },
        { "_NV_getThePreferredWeapon", CharacterHumanBinding::_NV_getThePreferredWeapon },
        { "_NV_getRangedWeapon", CharacterHumanBinding::_NV_getRangedWeapon },
        { "_NV_loadFromSerialise", CharacterHumanBinding::_NV_loadFromSerialise },
        { "_NV_giveBirth", CharacterHumanBinding::_NV_giveBirth },
        { "_NV_setupInventorySections", CharacterHumanBinding::_NV_setupInventorySections },
        { "_NV_validateInventorySections", CharacterHumanBinding::_NV_validateInventorySections },
        { "_NV_setupAudio", CharacterHumanBinding::_NV_setupAudio },
        { "shaveHead", CharacterHumanBinding::shaveHead },
        { "_NV_isHeadShaven", CharacterHumanBinding::_NV_isHeadShaven },
        { "_NV_createAnimationClass", CharacterHumanBinding::_NV_createAnimationClass },
        { "dropItem", CharacterHumanBinding::dropItem },
        { "_NV_dropItem", CharacterHumanBinding::_NV_dropItem },
        { "dropWeaponInHands", CharacterHumanBinding::dropWeaponInHands },
        { "dropWeaponInHandsFake", CharacterHumanBinding::dropWeaponInHandsFake },
        { "_NV_unequipItem", CharacterHumanBinding::_NV_unequipItem },
        { "_NV_weatherUpdate", CharacterHumanBinding::_NV_weatherUpdate },
        { "leaveSheathEquipped", CharacterHumanBinding::leaveSheathEquipped },
        { "_NV_postRagdollCallback", CharacterHumanBinding::_NV_postRagdollCallback },
        { "_NV_reCalculateNaturalWeapon", CharacterHumanBinding::_NV_reCalculateNaturalWeapon },
        { "_NV_serialise", CharacterHumanBinding::_NV_serialise },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterHumanBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterHumanBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "weaponInHands", CharacterHuman_get_weaponInHands);
    registerGetter(L, "weaponInHandsSheathLocation", CharacterHuman_get_weaponInHandsSheathLocation);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "weaponInHands", CharacterHuman_set_weaponInHands);
    registerSetter(L, "weaponInHandsSheathLocation", CharacterHuman_set_weaponInHandsSheathLocation);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
