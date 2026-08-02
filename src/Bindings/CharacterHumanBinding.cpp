#include "pch.h"
#include "kenshi\CharacterHuman.h"
#include "CharacterHumanBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/FactionBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameDataCopyStandaloneBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/WeaponBinding.h"
#include "CrossbowBinding.h"
#include "WeaponBinding.h"
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
    if (!instance) return luaL_error(L, "CharacterHuman is nil");
    return pushObject<Weapon>(L, instance->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterHuman_get_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");
    lua_pushstring(L, instance->weaponInHandsSheathLocation.c_str());
    return 1;
}

// --- Setters for CharacterHuman ---
static int CharacterHuman_set_weaponInHands(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");
    instance->weaponInHands = lua_isnoneornil(L, 2) ? nullptr : checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    return 0;
}

static int CharacterHuman_set_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");
    instance->weaponInHandsSheathLocation = luaL_checkstring(L, 2);
    return 0;
}

int CharacterHumanBinding::_CONSTRUCTOR(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameData* d = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    Faction* f = checkObject<Faction>(L, 3, FactionBinding::getMetatableName());
    hand _handle = *checkObject<hand>(L, 4, HandBinding::getMetatableName());
    CharacterHuman* result = instance->_CONSTRUCTOR(d, f, _handle);
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int CharacterHumanBinding::isHuman(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    CharacterHuman* result = instance->isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_isHuman(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    CharacterHuman* result = instance->_NV_isHuman();
    return pushObject<CharacterHuman>(L, result, CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::drawWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSection = luaL_checkstring(L, 3);
    bool result = instance->drawWeapon(item, lastSection);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_drawWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSection = luaL_checkstring(L, 3);
    bool result = instance->_NV_drawWeapon(item, lastSection);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::sheatheWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->sheatheWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_NV_sheatheWeapon();
    return 0;
}

int CharacterHumanBinding::getCurrentWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = instance->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = instance->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::getThePreferredWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = instance->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = instance->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::getRangedWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Crossbow* result = instance->getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getRangedWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    Crossbow* result = instance->_NV_getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterHumanBinding::loadFromSerialise(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->loadFromSerialise(state);
    return 0;
}

int CharacterHumanBinding::_NV_loadFromSerialise(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    instance->_NV_loadFromSerialise(state);
    return 0;
}

int CharacterHumanBinding::giveBirth(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameDataCopyStandalone* _appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    Ogre::Quaternion _rot;
    readQuaternion(L, 4, _rot);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->giveBirth(_appearance, _pos, _rot, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_giveBirth(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameDataCopyStandalone* _appearance = checkObject<GameDataCopyStandalone>(L, 2, GameDataCopyStandaloneBinding::getMetatableName());
    Ogre::Vector3 _pos;
    readVector3(L, 3, _pos);
    Ogre::Quaternion _rot;
    readQuaternion(L, 4, _rot);
    GameSaveState* state = checkObject<GameSaveState>(L, 5, GameSaveStateBinding::getMetatableName());
    ActivePlatoon* tempplatoonptr = checkObject<ActivePlatoon>(L, 6, ActivePlatoonBinding::getMetatableName());
    Faction* _faction = checkObject<Faction>(L, 7, FactionBinding::getMetatableName());
    bool result = instance->_NV_giveBirth(_appearance, _pos, _rot, state, tempplatoonptr, _faction);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::setupInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_setupInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool result = instance->_NV_setupInventorySections(state);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::validateInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->validateInventorySections();
    return 0;
}

int CharacterHumanBinding::_NV_validateInventorySections(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_NV_validateInventorySections();
    return 0;
}

int CharacterHumanBinding::setupAudio(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->setupAudio();
    return 0;
}

int CharacterHumanBinding::_NV_setupAudio(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_NV_setupAudio();
    return 0;
}

int CharacterHumanBinding::shaveHead(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->shaveHead(on);
    return 0;
}

int CharacterHumanBinding::isHeadShaven(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    bool result = instance->isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_isHeadShaven(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    bool result = instance->_NV_isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::createAnimationClass(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->createAnimationClass();
    return 0;
}

int CharacterHumanBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_NV_createAnimationClass();
    return 0;
}

int CharacterHumanBinding::dropItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::_NV_dropItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    instance->_NV_dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::dropWeaponInHands(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->dropWeaponInHands();
    return 0;
}

int CharacterHumanBinding::dropWeaponInHandsFake(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->dropWeaponInHandsFake();
    return 0;
}

int CharacterHumanBinding::unequipItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    const std::string section = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->unequipItem(section, item);
    return 0;
}

int CharacterHumanBinding::_NV_unequipItem(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    const std::string section = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    instance->_NV_unequipItem(section, item);
    return 0;
}

int CharacterHumanBinding::weatherUpdate(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->weatherUpdate(time);
    return 0;
}

int CharacterHumanBinding::_NV_weatherUpdate(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    float time = (float)luaL_checknumber(L, 2);
    instance->_NV_weatherUpdate(time);
    return 0;
}

int CharacterHumanBinding::leaveSheathEquipped(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    std::string section = luaL_checkstring(L, 2);
    int ypos = (int)luaL_checkinteger(L, 3);
    instance->leaveSheathEquipped(section, ypos);
    return 0;
}

int CharacterHumanBinding::postRagdollCallback(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->postRagdollCallback(on, part);
    return 0;
}

int CharacterHumanBinding::_NV_postRagdollCallback(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    instance->_NV_postRagdollCallback(on, part);
    return 0;
}

int CharacterHumanBinding::reCalculateNaturalWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->reCalculateNaturalWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_reCalculateNaturalWeapon(lua_State* L)
{
    CharacterHuman* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "CharacterHuman is nil");

    instance->_NV_reCalculateNaturalWeapon();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 30: GameSaveState serialise(...) - unsupported arg type
  line 31: GameSaveState _NV_serialise(...) - unsupported arg type
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
        { "_CONSTRUCTOR", CharacterHumanBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", CharacterHumanBinding::_DESTRUCTOR },
        { "isHuman", CharacterHumanBinding::isHuman },
        { "_NV_isHuman", CharacterHumanBinding::_NV_isHuman },
        { "drawWeapon", CharacterHumanBinding::drawWeapon },
        { "_NV_drawWeapon", CharacterHumanBinding::_NV_drawWeapon },
        { "sheatheWeapon", CharacterHumanBinding::sheatheWeapon },
        { "_NV_sheatheWeapon", CharacterHumanBinding::_NV_sheatheWeapon },
        { "getCurrentWeapon", CharacterHumanBinding::getCurrentWeapon },
        { "_NV_getCurrentWeapon", CharacterHumanBinding::_NV_getCurrentWeapon },
        { "getThePreferredWeapon", CharacterHumanBinding::getThePreferredWeapon },
        { "_NV_getThePreferredWeapon", CharacterHumanBinding::_NV_getThePreferredWeapon },
        { "getRangedWeapon", CharacterHumanBinding::getRangedWeapon },
        { "_NV_getRangedWeapon", CharacterHumanBinding::_NV_getRangedWeapon },
        { "loadFromSerialise", CharacterHumanBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", CharacterHumanBinding::_NV_loadFromSerialise },
        { "giveBirth", CharacterHumanBinding::giveBirth },
        { "_NV_giveBirth", CharacterHumanBinding::_NV_giveBirth },
        { "setupInventorySections", CharacterHumanBinding::setupInventorySections },
        { "_NV_setupInventorySections", CharacterHumanBinding::_NV_setupInventorySections },
        { "validateInventorySections", CharacterHumanBinding::validateInventorySections },
        { "_NV_validateInventorySections", CharacterHumanBinding::_NV_validateInventorySections },
        { "setupAudio", CharacterHumanBinding::setupAudio },
        { "_NV_setupAudio", CharacterHumanBinding::_NV_setupAudio },
        { "shaveHead", CharacterHumanBinding::shaveHead },
        { "isHeadShaven", CharacterHumanBinding::isHeadShaven },
        { "_NV_isHeadShaven", CharacterHumanBinding::_NV_isHeadShaven },
        { "createAnimationClass", CharacterHumanBinding::createAnimationClass },
        { "_NV_createAnimationClass", CharacterHumanBinding::_NV_createAnimationClass },
        { "dropItem", CharacterHumanBinding::dropItem },
        { "_NV_dropItem", CharacterHumanBinding::_NV_dropItem },
        { "dropWeaponInHands", CharacterHumanBinding::dropWeaponInHands },
        { "dropWeaponInHandsFake", CharacterHumanBinding::dropWeaponInHandsFake },
        { "unequipItem", CharacterHumanBinding::unequipItem },
        { "_NV_unequipItem", CharacterHumanBinding::_NV_unequipItem },
        { "weatherUpdate", CharacterHumanBinding::weatherUpdate },
        { "_NV_weatherUpdate", CharacterHumanBinding::_NV_weatherUpdate },
        { "leaveSheathEquipped", CharacterHumanBinding::leaveSheathEquipped },
        { "postRagdollCallback", CharacterHumanBinding::postRagdollCallback },
        { "_NV_postRagdollCallback", CharacterHumanBinding::_NV_postRagdollCallback },
        { "reCalculateNaturalWeapon", CharacterHumanBinding::reCalculateNaturalWeapon },
        { "_NV_reCalculateNaturalWeapon", CharacterHumanBinding::_NV_reCalculateNaturalWeapon },
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

    // Wire up inheritance to Character
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, CharacterHumanBinding::getMetatableName(), CharacterBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua