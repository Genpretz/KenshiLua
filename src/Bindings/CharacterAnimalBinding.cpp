#include "pch.h"
#include "kenshi\CharacterAnimal.h"
#include "CharacterAnimalBinding.h"
#include "WeaponBinding.h"
#include "kenshi/Item.h"
#include "ItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static CharacterAnimal* getB(lua_State* L, int idx)
{
    return checkObject<CharacterAnimal>(L, idx, CharacterAnimalBinding::getMetatableName());
}

// --- Getters for CharacterAnimal ---
static int CharacterAnimal_get_weaponIsTechnicallyEquipped(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushboolean(L, b->weaponIsTechnicallyEquipped ? 1 : 0);
    return 1;
}

static int CharacterAnimal_get_HPMultiplier(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->HPMultiplier);
    return 1;
}

static int CharacterAnimal_get_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    // TODO: Unsupported type for itemInMouthTimeStamp (TimeOfDay)
    lua_pushnil(L);
    return 1;
}

static int CharacterAnimal_get_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->smellThresholdBlood);
    return 1;
}

static int CharacterAnimal_get_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->smellThresholdEggs);
    return 1;
}

static int CharacterAnimal_get_ageSizeMin(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->ageSizeMin);
    return 1;
}

static int CharacterAnimal_get_ageSizeMax(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->ageSizeMax);
    return 1;
}

static int CharacterAnimal_get_lifespanInDays(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->lifespanInDays);
    return 1;
}

static int CharacterAnimal_get_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->lastUpdatedAge);
    return 1;
}

static int CharacterAnimal_get_age(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->age);
    return 1;
}

static int CharacterAnimal_get_weaponInHands(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    return pushObject<Weapon>(L, b->weaponInHands, WeaponBinding::getMetatableName());
}

static int CharacterAnimal_get_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    lua_pushnumber(L, b->audioTimeStamp);
    return 1;
}

// --- Setters for CharacterAnimal ---
static int CharacterAnimal_set_weaponIsTechnicallyEquipped(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->weaponIsTechnicallyEquipped = lua_toboolean(L, 2) != 0;
    return 0;
}

static int CharacterAnimal_set_HPMultiplier(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->HPMultiplier = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_itemInMouthTimeStamp(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    return luaL_error(L, "Read-only or unsupported setter type for itemInMouthTimeStamp");
}

static int CharacterAnimal_set_smellThresholdBlood(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->smellThresholdBlood = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_smellThresholdEggs(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->smellThresholdEggs = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMin(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->ageSizeMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_ageSizeMax(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->ageSizeMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lifespanInDays(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->lifespanInDays = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_lastUpdatedAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->lastUpdatedAge = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_age(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->age = (float)luaL_checknumber(L, 2);
    return 0;
}

static int CharacterAnimal_set_weaponInHands(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    return luaL_error(L, "Read-only or unsupported setter type for weaponInHands");
}

static int CharacterAnimal_set_audioTimeStamp(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");
    b->audioTimeStamp = (float)luaL_checknumber(L, 2);
    return 0;
}

int CharacterAnimalBinding::isAnimal(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    CharacterAnimal* result = b->isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_isAnimal(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    CharacterAnimal* result = b->_NV_isAnimal();
    return pushObject<CharacterAnimal>(L, result, CharacterAnimalBinding::getMetatableName());
}

int CharacterAnimalBinding::createAnimationClass(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->createAnimationClass();
    return 0;
}

int CharacterAnimalBinding::_NV_createAnimationClass(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_createAnimationClass();
    return 0;
}

int CharacterAnimalBinding::sheatheWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->sheatheWeapon();
    return 0;
}

int CharacterAnimalBinding::_NV_sheatheWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_sheatheWeapon();
    return 0;
}

int CharacterAnimalBinding::getCurrentWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = b->getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_getCurrentWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = b->_NV_getCurrentWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::getThePreferredWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = b->getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::_NV_getThePreferredWeapon(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    Weapon* result = b->_NV_getThePreferredWeapon();
    return pushObject<Weapon>(L, result, WeaponBinding::getMetatableName());
}

int CharacterAnimalBinding::setupAudio(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->setupAudio();
    return 0;
}

int CharacterAnimalBinding::_NV_setupAudio(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_setupAudio();
    return 0;
}

int CharacterAnimalBinding::periodicUpdate(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->periodicUpdate();
    return 0;
}

int CharacterAnimalBinding::_NV_periodicUpdate(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_periodicUpdate();
    return 0;
}

int CharacterAnimalBinding::setAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float zeroToOne = (float)luaL_checknumber(L, 2);
    b->setAge(zeroToOne);
    return 0;
}

int CharacterAnimalBinding::_NV_setAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float zeroToOne = (float)luaL_checknumber(L, 2);
    b->_NV_setAge(zeroToOne);
    return 0;
}

int CharacterAnimalBinding::getAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAge(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getAge();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getAgeInverse(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAgeInverse(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getAgeInverse();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getAge0to1(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getAge0to1(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getAge0to1();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getDefaultTaskRepertoireEnum(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    unsigned int result = b->getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    unsigned int result = b->_NV_getDefaultTaskRepertoireEnum();
    lua_pushinteger(L, result);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getSmellHuntingThresholdBlood();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getSmellHuntingThresholdEggs();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::getHPMultiplier(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::_NV_getHPMultiplier(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    float result = b->_NV_getHPMultiplier();
    lua_pushnumber(L, result);
    return 1;
}

int CharacterAnimalBinding::foodUpdate(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->foodUpdate();
    return 0;
}

int CharacterAnimalBinding::_NV_foodUpdate(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_foodUpdate();
    return 0;
}

int CharacterAnimalBinding::dropItemInMouth(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    bool result = b->dropItemInMouth();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int CharacterAnimalBinding::getItemInMouth(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    Item* result = b->getItemInMouth();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int CharacterAnimalBinding::eatItemInMouth(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->eatItemInMouth();
    return 0;
}

int CharacterAnimalBinding::_DESTRUCTOR(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_DESTRUCTOR();
    return 0;
}

int CharacterAnimalBinding::init(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->init();
    return 0;
}

int CharacterAnimalBinding::_NV_init(lua_State* L)
{
    CharacterAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "CharacterAnimal is nil");

    b->_NV_init();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 34: bool drawWeapon(...) - unsupported arg type
  line 35: bool _NV_drawWeapon(...) - unsupported arg type
  line 42: InventoryLayout* createInventoryLayout(...) - unsupported return type
  line 43: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
  line 44: bool giveBirth(...) - unsupported arg type
  line 45: bool _NV_giveBirth(...) - unsupported arg type
  line 46: bool setupInventorySections(...) - unsupported arg type
  line 47: bool _NV_setupInventorySections(...) - unsupported arg type
  line 62: bool canGoIndoors(...) - unsupported arg type
  line 63: bool _NV_canGoIndoors(...) - unsupported arg type
  line 75: bool pickupItemInMouth(...) - unsupported arg type
  line 81: CharacterAnimal* _CONSTRUCTOR(...) - unsupported arg type
  line 86: void dropItem(...) - unsupported arg type
  line 87: void _NV_dropItem(...) - unsupported arg type
*/

int CharacterAnimalBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int CharacterAnimalBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.CharacterAnimal object");
    return 1;
}

void CharacterAnimalBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CharacterAnimalBinding::gc },
        { "__tostring", CharacterAnimalBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isAnimal", CharacterAnimalBinding::isAnimal },
        { "_NV_isAnimal", CharacterAnimalBinding::_NV_isAnimal },
        { "createAnimationClass", CharacterAnimalBinding::createAnimationClass },
        { "_NV_createAnimationClass", CharacterAnimalBinding::_NV_createAnimationClass },
        { "sheatheWeapon", CharacterAnimalBinding::sheatheWeapon },
        { "_NV_sheatheWeapon", CharacterAnimalBinding::_NV_sheatheWeapon },
        { "getCurrentWeapon", CharacterAnimalBinding::getCurrentWeapon },
        { "_NV_getCurrentWeapon", CharacterAnimalBinding::_NV_getCurrentWeapon },
        { "getThePreferredWeapon", CharacterAnimalBinding::getThePreferredWeapon },
        { "_NV_getThePreferredWeapon", CharacterAnimalBinding::_NV_getThePreferredWeapon },
        { "setupAudio", CharacterAnimalBinding::setupAudio },
        { "_NV_setupAudio", CharacterAnimalBinding::_NV_setupAudio },
        { "periodicUpdate", CharacterAnimalBinding::periodicUpdate },
        { "_NV_periodicUpdate", CharacterAnimalBinding::_NV_periodicUpdate },
        { "setAge", CharacterAnimalBinding::setAge },
        { "_NV_setAge", CharacterAnimalBinding::_NV_setAge },
        { "getAge", CharacterAnimalBinding::getAge },
        { "_NV_getAge", CharacterAnimalBinding::_NV_getAge },
        { "getAgeInverse", CharacterAnimalBinding::getAgeInverse },
        { "_NV_getAgeInverse", CharacterAnimalBinding::_NV_getAgeInverse },
        { "getAge0to1", CharacterAnimalBinding::getAge0to1 },
        { "_NV_getAge0to1", CharacterAnimalBinding::_NV_getAge0to1 },
        { "getDefaultTaskRepertoireEnum", CharacterAnimalBinding::getDefaultTaskRepertoireEnum },
        { "_NV_getDefaultTaskRepertoireEnum", CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum },
        { "getSmellHuntingThresholdBlood", CharacterAnimalBinding::getSmellHuntingThresholdBlood },
        { "_NV_getSmellHuntingThresholdBlood", CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood },
        { "getSmellHuntingThresholdEggs", CharacterAnimalBinding::getSmellHuntingThresholdEggs },
        { "_NV_getSmellHuntingThresholdEggs", CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs },
        { "getHPMultiplier", CharacterAnimalBinding::getHPMultiplier },
        { "_NV_getHPMultiplier", CharacterAnimalBinding::_NV_getHPMultiplier },
        { "foodUpdate", CharacterAnimalBinding::foodUpdate },
        { "_NV_foodUpdate", CharacterAnimalBinding::_NV_foodUpdate },
        { "dropItemInMouth", CharacterAnimalBinding::dropItemInMouth },
        { "getItemInMouth", CharacterAnimalBinding::getItemInMouth },
        { "eatItemInMouth", CharacterAnimalBinding::eatItemInMouth },
        { "_DESTRUCTOR", CharacterAnimalBinding::_DESTRUCTOR },
        { "init", CharacterAnimalBinding::init },
        { "_NV_init", CharacterAnimalBinding::_NV_init },
        { 0, 0 }
    };

    registerClass(
        L, 
        CharacterAnimalBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, CharacterAnimalBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, CharacterAnimal_get_weaponIsTechnicallyEquipped);
    lua_setfield(L, -2, "weaponIsTechnicallyEquipped");
    lua_pushcfunction(L, CharacterAnimal_get_HPMultiplier);
    lua_setfield(L, -2, "HPMultiplier");
    lua_pushcfunction(L, CharacterAnimal_get_itemInMouthTimeStamp);
    lua_setfield(L, -2, "itemInMouthTimeStamp");
    lua_pushcfunction(L, CharacterAnimal_get_smellThresholdBlood);
    lua_setfield(L, -2, "smellThresholdBlood");
    lua_pushcfunction(L, CharacterAnimal_get_smellThresholdEggs);
    lua_setfield(L, -2, "smellThresholdEggs");
    lua_pushcfunction(L, CharacterAnimal_get_ageSizeMin);
    lua_setfield(L, -2, "ageSizeMin");
    lua_pushcfunction(L, CharacterAnimal_get_ageSizeMax);
    lua_setfield(L, -2, "ageSizeMax");
    lua_pushcfunction(L, CharacterAnimal_get_lifespanInDays);
    lua_setfield(L, -2, "lifespanInDays");
    lua_pushcfunction(L, CharacterAnimal_get_lastUpdatedAge);
    lua_setfield(L, -2, "lastUpdatedAge");
    lua_pushcfunction(L, CharacterAnimal_get_age);
    lua_setfield(L, -2, "age");
    lua_pushcfunction(L, CharacterAnimal_get_weaponInHands);
    lua_setfield(L, -2, "weaponInHands");
    lua_pushcfunction(L, CharacterAnimal_get_audioTimeStamp);
    lua_setfield(L, -2, "audioTimeStamp");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, CharacterAnimal_set_weaponIsTechnicallyEquipped);
    lua_setfield(L, -2, "weaponIsTechnicallyEquipped");
    lua_pushcfunction(L, CharacterAnimal_set_HPMultiplier);
    lua_setfield(L, -2, "HPMultiplier");
    lua_pushcfunction(L, CharacterAnimal_set_itemInMouthTimeStamp);
    lua_setfield(L, -2, "itemInMouthTimeStamp");
    lua_pushcfunction(L, CharacterAnimal_set_smellThresholdBlood);
    lua_setfield(L, -2, "smellThresholdBlood");
    lua_pushcfunction(L, CharacterAnimal_set_smellThresholdEggs);
    lua_setfield(L, -2, "smellThresholdEggs");
    lua_pushcfunction(L, CharacterAnimal_set_ageSizeMin);
    lua_setfield(L, -2, "ageSizeMin");
    lua_pushcfunction(L, CharacterAnimal_set_ageSizeMax);
    lua_setfield(L, -2, "ageSizeMax");
    lua_pushcfunction(L, CharacterAnimal_set_lifespanInDays);
    lua_setfield(L, -2, "lifespanInDays");
    lua_pushcfunction(L, CharacterAnimal_set_lastUpdatedAge);
    lua_setfield(L, -2, "lastUpdatedAge");
    lua_pushcfunction(L, CharacterAnimal_set_age);
    lua_setfield(L, -2, "age");
    lua_pushcfunction(L, CharacterAnimal_set_weaponInHands);
    lua_setfield(L, -2, "weaponInHands");
    lua_pushcfunction(L, CharacterAnimal_set_audioTimeStamp);
    lua_setfield(L, -2, "audioTimeStamp");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua