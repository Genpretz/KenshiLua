#include "pch.h"
<<<<<<< HEAD:src/Bindings/Character/CharacterAnimalBinding.cpp
#include "Bindings/Character/CharacterAnimalBinding.h"
=======
#include "kenshi\CharacterAnimal.h"
#include "CharacterAnimalBinding.h"
#include "WeaponBinding.h"
#include "kenshi/Item.h"
#include "ItemBinding.h"
>>>>>>> main:src/Bindings/CharacterAnimalBinding.cpp
#include "Lua/BindingHelpers.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/WeaponBinding.h"

namespace KenshiLua
{

<<<<<<< HEAD:src/Bindings/Character/CharacterAnimalBinding.cpp
// -----------------------------------------------
// AnimalInventoryLayoutBinding
// -----------------------------------------------

    static AnimalInventoryLayout* getAIL(lua_State* L, int idx)
    {
        return checkObject<AnimalInventoryLayout>(L, idx, AnimalInventoryLayoutBinding::getMetatableName());
    }

    int AnimalInventoryLayoutBinding::gc(lua_State* L) { return noopGc(L); }

    int AnimalInventoryLayoutBinding::tostring(lua_State* L)
    {
        AnimalInventoryLayout* s = getAIL(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int AnimalInventoryLayoutBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, AnimalInventoryLayoutBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        AnimalInventoryLayout* s = getAIL(L, 1);
        if (!s) { lua_pushnil(L); return 1; }


        lua_pushnil(L);
        return 1;
    }

    int AnimalInventoryLayoutBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        AnimalInventoryLayout* s = getAIL(L, 1);
        if (!s) return luaL_error(L, "AnimalInventoryLayout is nil");


        return luaL_error(L, "unknown or read-only field '%s'", key);
    }

    int AnimalInventoryLayoutBinding::_DESTRUCTOR(lua_State* L)
    {
        AnimalInventoryLayout* s = getAIL(L, 1);
        if (!s) return luaL_error(L, "AnimalInventoryLayout is nil");

        s->_DESTRUCTOR();
        return 0;
    }

    /*
    Skipped methods needing manual binding:
    line 15: AnimalInventoryLayout* _CONSTRUCTOR(...) - unsupported return type
    line 16: void setupSections(...) - unsupported arg type
    line 17: void _NV_setupSections(...) - unsupported arg type
    */

    void AnimalInventoryLayoutBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       AnimalInventoryLayoutBinding::gc },
            { "__tostring", AnimalInventoryLayoutBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "_DESTRUCTOR", AnimalInventoryLayoutBinding::_DESTRUCTOR },
            { 0, 0 }
        };
        registerClass(L, AnimalInventoryLayoutBinding::getMetatableName(), meta, methods, AnimalInventoryLayoutBinding::index, AnimalInventoryLayoutBinding::newindex);
    }

// -----------------------------------------------
// CharacterAnimalBinding
// -----------------------------------------------

    static CharacterAnimal* getCA(lua_State* L, int idx)
    {
        return checkObject<CharacterAnimal>(L, idx, CharacterAnimalBinding::getMetatableName());
    }

    int CharacterAnimalBinding::gc(lua_State* L) { return noopGc(L); }

    int CharacterAnimalBinding::tostring(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        return genericTostringPtr(L, "%s", s);
    }

    int CharacterAnimalBinding::index(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);

        luaL_getmetatable(L, CharacterAnimalBinding::getMetatableName());
        lua_getfield(L, -1, key);
        if (!lua_isnil(L, -1))
            return 1;
        lua_pop(L, 2);

        CharacterAnimal* s = getCA(L, 1);
        if (!s) { lua_pushnil(L); return 1; }

        if (strcmp(key, "weaponIsTechnicallyEquipped") == 0) { lua_pushboolean(L, s->weaponIsTechnicallyEquipped ? 1 : 0); return 1; }
        if (strcmp(key, "HPMultiplier") == 0) { lua_pushnumber(L, s->HPMultiplier); return 1; }
        // TODO TimeOfDay itemInMouthTimeStamp; unsupported __index type from header line 72
        if (strcmp(key, "smellThresholdBlood") == 0) { lua_pushnumber(L, s->smellThresholdBlood); return 1; }
        if (strcmp(key, "smellThresholdEggs") == 0) { lua_pushnumber(L, s->smellThresholdEggs); return 1; }
        if (strcmp(key, "ageSizeMin") == 0) { lua_pushnumber(L, s->ageSizeMin); return 1; }
        if (strcmp(key, "ageSizeMax") == 0) { lua_pushnumber(L, s->ageSizeMax); return 1; }
        if (strcmp(key, "lifespanInDays") == 0) { lua_pushnumber(L, s->lifespanInDays); return 1; }
        if (strcmp(key, "lastUpdatedAge") == 0) { lua_pushnumber(L, s->lastUpdatedAge); return 1; }
        if (strcmp(key, "age") == 0) { lua_pushnumber(L, s->age); return 1; }
        // TODO Weapon* weaponInHands; unsupported __index type from header line 95
        if (strcmp(key, "audioTimeStamp") == 0) { lua_pushnumber(L, s->audioTimeStamp); return 1; }

        lua_pushnil(L);
        return 1;
    }

    int CharacterAnimalBinding::newindex(lua_State* L)
    {
        const char* key = luaL_checkstring(L, 2);
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        if (strcmp(key, "weaponIsTechnicallyEquipped") == 0) { s->weaponIsTechnicallyEquipped = lua_toboolean(L, 3) != 0; return 0; }
        if (strcmp(key, "HPMultiplier") == 0) { s->HPMultiplier = (float)luaL_checknumber(L, 3); return 0; }
        // TODO TimeOfDay itemInMouthTimeStamp; unsupported __newindex type from header line 72
        if (strcmp(key, "smellThresholdBlood") == 0) { s->smellThresholdBlood = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "smellThresholdEggs") == 0) { s->smellThresholdEggs = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "ageSizeMin") == 0) { s->ageSizeMin = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "ageSizeMax") == 0) { s->ageSizeMax = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "lifespanInDays") == 0) { s->lifespanInDays = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "lastUpdatedAge") == 0) { s->lastUpdatedAge = (float)luaL_checknumber(L, 3); return 0; }
        if (strcmp(key, "age") == 0) { s->age = (float)luaL_checknumber(L, 3); return 0; }
        // TODO Weapon* weaponInHands; unsupported __newindex type from header line 95
        if (strcmp(key, "audioTimeStamp") == 0) { s->audioTimeStamp = (float)luaL_checknumber(L, 3); return 0; }

        return luaL_error(L, "unknown or read-only field '%s'", key);
    }

    int CharacterAnimalBinding::createAnimationClass(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->createAnimationClass();
        return 0;
    }

    int CharacterAnimalBinding::_NV_createAnimationClass(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_createAnimationClass();
        return 0;
    }

    int CharacterAnimalBinding::sheatheWeapon(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->sheatheWeapon();
        return 0;
    }

    int CharacterAnimalBinding::_NV_sheatheWeapon(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_sheatheWeapon();
        return 0;
    }

    int CharacterAnimalBinding::setupAudio(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->setupAudio();
        return 0;
    }

    int CharacterAnimalBinding::_NV_setupAudio(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_setupAudio();
        return 0;
    }

    int CharacterAnimalBinding::periodicUpdate(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->periodicUpdate();
        return 0;
    }

    int CharacterAnimalBinding::_NV_periodicUpdate(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_periodicUpdate();
        return 0;
    }

    int CharacterAnimalBinding::setAge(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float zeroToOne = (float)luaL_checknumber(L, 2);
        s->setAge(zeroToOne);
        return 0;
    }

    int CharacterAnimalBinding::_NV_setAge(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float zeroToOne = (float)luaL_checknumber(L, 2);
        s->_NV_setAge(zeroToOne);
        return 0;
    }

    int CharacterAnimalBinding::getAge(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getAge();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getAge(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getAge();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getAgeInverse(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getAgeInverse();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getAgeInverse(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getAgeInverse();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getAge0to1(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getAge0to1();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getAge0to1(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getAge0to1();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getDefaultTaskRepertoireEnum(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        unsigned int result = s->getDefaultTaskRepertoireEnum();
        lua_pushinteger(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getDefaultTaskRepertoireEnum(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        unsigned int result = s->_NV_getDefaultTaskRepertoireEnum();
        lua_pushinteger(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getSmellHuntingThresholdBlood(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getSmellHuntingThresholdBlood();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getSmellHuntingThresholdBlood(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getSmellHuntingThresholdBlood();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getSmellHuntingThresholdEggs(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getSmellHuntingThresholdEggs();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getSmellHuntingThresholdEggs(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getSmellHuntingThresholdEggs();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::getHPMultiplier(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->getHPMultiplier();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::_NV_getHPMultiplier(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        float result = s->_NV_getHPMultiplier();
        lua_pushnumber(L, result);
        return 1;
    }

    int CharacterAnimalBinding::foodUpdate(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->foodUpdate();
        return 0;
    }

    int CharacterAnimalBinding::_NV_foodUpdate(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_foodUpdate();
        return 0;
    }

    int CharacterAnimalBinding::dropItemInMouth(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        bool result = s->dropItemInMouth();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int CharacterAnimalBinding::eatItemInMouth(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->eatItemInMouth();
        return 0;
    }

    int CharacterAnimalBinding::_DESTRUCTOR(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_DESTRUCTOR();
        return 0;
    }

    int CharacterAnimalBinding::init(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->init();
        return 0;
    }

    int CharacterAnimalBinding::_NV_init(lua_State* L)
    {
        CharacterAnimal* s = getCA(L, 1);
        if (!s) return luaL_error(L, "CharacterAnimal is nil");

        s->_NV_init();
        return 0;
    }

    /*
    Skipped methods needing manual binding:
    line 29: CharacterAnimal* isAnimal(...) - unsupported return type
    line 30: CharacterAnimal* _NV_isAnimal(...) - unsupported return type
    line 34: bool drawWeapon(...) - unsupported arg type
    line 35: bool _NV_drawWeapon(...) - unsupported arg type
    line 38: Weapon* getCurrentWeapon(...) - unsupported return type
    line 39: Weapon* _NV_getCurrentWeapon(...) - unsupported return type
    line 40: Weapon* getThePreferredWeapon(...) - unsupported return type
    line 41: Weapon* _NV_getThePreferredWeapon(...) - unsupported return type
    line 42: InventoryLayout* createInventoryLayout(...) - unsupported return type
    line 43: InventoryLayout* _NV_createInventoryLayout(...) - unsupported return type
    line 44: bool giveBirth(...) - unsupported arg type
    line 45: bool _NV_giveBirth(...) - unsupported arg type
    line 46: bool setupInventorySections(...) - unsupported arg type
    line 47: bool _NV_setupInventorySections(...) - unsupported arg type
    line 62: bool canGoIndoors(...) - unsupported arg type
    line 63: bool _NV_canGoIndoors(...) - unsupported arg type
    line 75: bool pickupItemInMouth(...) - unsupported arg type
    line 77: Item* getItemInMouth(...) - unsupported return type
    line 81: CharacterAnimal* _CONSTRUCTOR(...) - unsupported return type
    line 86: void dropItem(...) - unsupported arg type
    line 87: void _NV_dropItem(...) - unsupported arg type
    */

    void CharacterAnimalBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       CharacterAnimalBinding::gc },
            { "__tostring", CharacterAnimalBinding::tostring },
            { 0, 0 }
        };
        static const luaL_Reg methods[] = {
            { "createAnimationClass", CharacterAnimalBinding::createAnimationClass },
            { "_NV_createAnimationClass", CharacterAnimalBinding::_NV_createAnimationClass },
            { "sheatheWeapon", CharacterAnimalBinding::sheatheWeapon },
            { "_NV_sheatheWeapon", CharacterAnimalBinding::_NV_sheatheWeapon },
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
            { "eatItemInMouth", CharacterAnimalBinding::eatItemInMouth },
            { "_DESTRUCTOR", CharacterAnimalBinding::_DESTRUCTOR },
            { "init", CharacterAnimalBinding::init },
            { "_NV_init", CharacterAnimalBinding::_NV_init },
            { 0, 0 }
        };
        registerClass(L, CharacterAnimalBinding::getMetatableName(), meta, methods, CharacterAnimalBinding::index, CharacterAnimalBinding::newindex);
    }
=======
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
    return luaL_error(L, "Unsupported property 'itemInMouthTimeStamp' (type: TimeOfDay)");
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
>>>>>>> main:src/Bindings/CharacterAnimalBinding.cpp

} // namespace KenshiLua