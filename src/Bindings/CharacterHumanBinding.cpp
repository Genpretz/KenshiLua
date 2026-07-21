#include "pch.h"
#include "kenshi\CharacterHuman.h"
#include "CharacterHumanBinding.h"
#include "kenshi/Gear.h"
#include "WeaponBinding.h"
#include "CrossbowBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CrossbowBinding.h"
#include "Bindings/WeaponBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/RootObjectBinding.h"

namespace KenshiLua
{

static CharacterHuman* getB(lua_State* L, int idx)
{
    return checkObject<CharacterHuman>(L, idx, CharacterHumanBinding::getMetatableName());
}

// --- Getters for CharacterHuman ---
static int CharacterHuman_get_weaponInHands(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    return pushObject<Weapon>(L, b->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterHuman_get_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    lua_pushstring(L, b->weaponInHandsSheathLocation.c_str());
    return 1;
}

// --- Setters for CharacterHuman ---
static int CharacterHuman_set_weaponInHands(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    b->weaponInHands = lua_isnoneornil(L, 2) ? nullptr : checkObject<Weapon>(L, 2, WeaponBinding::getMetatableName());
    return 0;
}

static int CharacterHuman_set_weaponInHandsSheathLocation(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    b->weaponInHandsSheathLocation = luaL_checkstring(L, 2);
    return 0;
}

int CharacterHumanBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_DESTRUCTOR();
    return 0;
}

int CharacterHumanBinding::sheatheWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->sheatheWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_NV_sheatheWeapon();
    return 0;
}

int CharacterHumanBinding::getCurrentWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = b->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = b->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::getThePreferredWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = b->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Weapon* result = b->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterHumanBinding::getRangedWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Crossbow* result = b->getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_getRangedWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    Crossbow* result = b->_NV_getRangedWeapon();
    return pushObject<Crossbow>(L, result, CrossbowBinding::getMetatableName());
}

int CharacterHumanBinding::validateInventorySections(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->validateInventorySections();
    return 0;
}

int CharacterHumanBinding::_NV_validateInventorySections(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_NV_validateInventorySections();
    return 0;
}

int CharacterHumanBinding::setupAudio(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->setupAudio();
    return 0;
}

int CharacterHumanBinding::_NV_setupAudio(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_NV_setupAudio();
    return 0;
}

int CharacterHumanBinding::shaveHead(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    b->shaveHead(on);
    return 0;
}

int CharacterHumanBinding::isHeadShaven(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    bool result = b->isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_isHeadShaven(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    bool result = b->_NV_isHeadShaven();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::createAnimationClass(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->createAnimationClass();
    return 0;
}

int CharacterHumanBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_NV_createAnimationClass();
    return 0;
}

int CharacterHumanBinding::dropWeaponInHands(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->dropWeaponInHands();
    return 0;
}

int CharacterHumanBinding::dropWeaponInHandsFake(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->dropWeaponInHandsFake();
    return 0;
}

int CharacterHumanBinding::weatherUpdate(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->weatherUpdate(time);
    return 0;
}

int CharacterHumanBinding::_NV_weatherUpdate(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    float time = (float)luaL_checknumber(L, 2);
    b->_NV_weatherUpdate(time);
    return 0;
}

int CharacterHumanBinding::leaveSheathEquipped(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    std::string section = luaL_checkstring(L, 2);
    int ypos = (int)luaL_checkinteger(L, 3);
    b->leaveSheathEquipped(section, ypos);
    return 0;
}

int CharacterHumanBinding::postRagdollCallback(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    b->postRagdollCallback(on, part);
    return 0;
}

int CharacterHumanBinding::_NV_postRagdollCallback(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    bool on = lua_toboolean(L, 2) != 0;
    RagdollPart::Enum part = (RagdollPart::Enum)luaL_checkinteger(L, 3);
    b->_NV_postRagdollCallback(on, part);
    return 0;
}

int CharacterHumanBinding::reCalculateNaturalWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->reCalculateNaturalWeapon();
    return 0;
}

int CharacterHumanBinding::_NV_reCalculateNaturalWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");

    b->_NV_reCalculateNaturalWeapon();
    return 0;
}

int CharacterHumanBinding::isHuman(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    return pushObject<CharacterHuman>(L, b->isHuman(), CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::_NV_isHuman(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    return pushObject<CharacterHuman>(L, b->_NV_isHuman(), CharacterHumanBinding::getMetatableName());
}

int CharacterHumanBinding::drawWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSection = luaL_checkstring(L, 3);
    bool result = b->drawWeapon(item, lastSection);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::_NV_drawWeapon(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    Item* item = checkObject<Item>(L, 2, ItemBinding::getMetatableName());
    std::string lastSection = luaL_checkstring(L, 3);
    bool result = b->_NV_drawWeapon(item, lastSection);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterHumanBinding::dropItem(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::_NV_dropItem(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    RootObject* itembase = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    b->_NV_dropItem(itembase);
    return 0;
}

int CharacterHumanBinding::unequipItem(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    std::string section = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->unequipItem(section, item);
    return 0;
}

int CharacterHumanBinding::_NV_unequipItem(lua_State* L)
{
    CharacterHuman* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterHuman is nil");
    std::string section = luaL_checkstring(L, 2);
    Item* item = checkObject<Item>(L, 3, ItemBinding::getMetatableName());
    b->_NV_unequipItem(section, item);
    return 0;
}

/*
Skipped methods needing manual binding:
  line 15: CharacterHuman* _CONSTRUCTOR(...) - overloaded constructor / factory
  line 30: GameSaveState serialise(...) - unsupported return type
  line 31: GameSaveState _NV_serialise(...) - unsupported return type
  line 32: void loadFromSerialise(...) - unsupported arg type
  line 33: void _NV_loadFromSerialise(...) - unsupported arg type
  line 34: bool giveBirth(...) - unsupported arg type
  line 35: bool _NV_giveBirth(...) - unsupported arg type
  line 36: bool setupInventorySections(...) - unsupported arg type
  line 37: bool _NV_setupInventorySections(...) - unsupported arg type
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
        { "_DESTRUCTOR", CharacterHumanBinding::_DESTRUCTOR },
        { "sheatheWeapon", CharacterHumanBinding::sheatheWeapon },
        { "_NV_sheatheWeapon", CharacterHumanBinding::_NV_sheatheWeapon },
        { "getCurrentWeapon", CharacterHumanBinding::getCurrentWeapon },
        { "_NV_getCurrentWeapon", CharacterHumanBinding::_NV_getCurrentWeapon },
        { "getThePreferredWeapon", CharacterHumanBinding::getThePreferredWeapon },
        { "_NV_getThePreferredWeapon", CharacterHumanBinding::_NV_getThePreferredWeapon },
        { "getRangedWeapon", CharacterHumanBinding::getRangedWeapon },
        { "_NV_getRangedWeapon", CharacterHumanBinding::_NV_getRangedWeapon },
        { "validateInventorySections", CharacterHumanBinding::validateInventorySections },
        { "_NV_validateInventorySections", CharacterHumanBinding::_NV_validateInventorySections },
        { "setupAudio", CharacterHumanBinding::setupAudio },
        { "_NV_setupAudio", CharacterHumanBinding::_NV_setupAudio },
        { "shaveHead", CharacterHumanBinding::shaveHead },
        { "isHeadShaven", CharacterHumanBinding::isHeadShaven },
        { "_NV_isHeadShaven", CharacterHumanBinding::_NV_isHeadShaven },
        { "createAnimationClass", CharacterHumanBinding::createAnimationClass },
        { "_NV_createAnimationClass", CharacterHumanBinding::_NV_createAnimationClass },
        { "dropWeaponInHands", CharacterHumanBinding::dropWeaponInHands },
        { "dropWeaponInHandsFake", CharacterHumanBinding::dropWeaponInHandsFake },
        { "weatherUpdate", CharacterHumanBinding::weatherUpdate },
        { "_NV_weatherUpdate", CharacterHumanBinding::_NV_weatherUpdate },
        { "leaveSheathEquipped", CharacterHumanBinding::leaveSheathEquipped },
        { "postRagdollCallback", CharacterHumanBinding::postRagdollCallback },
        { "_NV_postRagdollCallback", CharacterHumanBinding::_NV_postRagdollCallback },
        { "reCalculateNaturalWeapon", CharacterHumanBinding::reCalculateNaturalWeapon },
        { "_NV_reCalculateNaturalWeapon", CharacterHumanBinding::_NV_reCalculateNaturalWeapon },
        { "isHuman", CharacterHumanBinding::isHuman },
        { "_NV_isHuman", CharacterHumanBinding::_NV_isHuman },
        { "drawWeapon", CharacterHumanBinding::drawWeapon },
        { "_NV_drawWeapon", CharacterHumanBinding::_NV_drawWeapon },
        { "dropItem", CharacterHumanBinding::dropItem },
        { "_NV_dropItem", CharacterHumanBinding::_NV_dropItem },
        { "unequipItem", CharacterHumanBinding::unequipItem },
        { "_NV_unequipItem", CharacterHumanBinding::_NV_unequipItem },
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
    lua_pushcfunction(L, CharacterHuman_get_weaponInHands);
    lua_setfield(L, -2, "weaponInHands");
    lua_pushcfunction(L, CharacterHuman_get_weaponInHandsSheathLocation);
    lua_setfield(L, -2, "weaponInHandsSheathLocation");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharacterHuman_set_weaponInHands);
    lua_setfield(L, -2, "weaponInHands");
    lua_pushcfunction(L, CharacterHuman_set_weaponInHandsSheathLocation);
    lua_setfield(L, -2, "weaponInHandsSheathLocation");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
