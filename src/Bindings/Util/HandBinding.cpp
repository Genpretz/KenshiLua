#include "pch.h"
#include "kenshi\util\hand.h"
#include "handBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/TownBaseBinding.h"

std::size_t hash_value(const hand& h)
{
    std::size_t seed = 0;
    boost::hash_combine(seed, (int)h.type);
    boost::hash_combine(seed, h.container);
    boost::hash_combine(seed, h.containerSerial);
    boost::hash_combine(seed, h.index);
    boost::hash_combine(seed, h.serial);
    return seed;
}

namespace KenshiLua
{

static hand* getInstance(lua_State* L, int idx)
{
    return checkObject<hand>(L, idx, handBinding::getMetatableName());
}

// --- Getters for hand ---
static int hand_get_type(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int hand_get_container(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->container);
    return 1;
}

static int hand_get_containerSerial(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->containerSerial);
    return 1;
}

static int hand_get_index(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

static int hand_get_serial(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->serial);
    return 1;
}

// --- Setters for hand ---
static int hand_set_type(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->type = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_container(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->container = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_containerSerial(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->containerSerial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_index(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->index = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_serial(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->serial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int handBinding::toString(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    std::string result = instance->toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int handBinding::fromString(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    const std::string str = luaL_checkstring(L, 2);
    instance->fromString(str);
    return 0;
}

int handBinding::getCharacter(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int handBinding::getPlatoon(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Platoon* result = instance->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int handBinding::getActivePlatoon(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    ActivePlatoon* result = instance->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int handBinding::getBuilding(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Building* result = instance->getBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int handBinding::getItem(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Item* result = instance->getItem();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int handBinding::getRootObject(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    RootObject* result = instance->getRootObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int handBinding::getRootObjectBase(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    RootObjectBase* result = instance->getRootObjectBase();
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

int handBinding::getTown(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    TownBase* result = instance->getTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int handBinding::debugWhatHappenedToMe(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    std::string result = instance->debugWhatHappenedToMe();
    lua_pushstring(L, result.c_str());
    return 1;
}

int handBinding::setNull(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    instance->setNull();
    return 0;
}

int handBinding::isNull(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->isNull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int handBinding::isValid(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int handBinding::canCastToRootObject(lua_State* L)
{
    hand* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->canCastToRootObject();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 22: hand* _CONSTRUCTOR(...) - overloaded method
  line 24: hand* _CONSTRUCTOR(...) - overloaded method
  line 26: hand* _CONSTRUCTOR(...) - overloaded method
  line 28: hand* _CONSTRUCTOR(...) - overloaded method
  line 30: hand* _CONSTRUCTOR(...) - overloaded method
  line 32: hand* _CONSTRUCTOR(...) - overloaded method
  line 40: bool operator==(...) - operator
  line 41: bool _NV_operator_equal(...) - overloaded method
  line 42: bool operator==(...) - operator
  line 43: bool operator==(...) - operator
  line 44: bool _NV_operator_equal(...) - overloaded method
  line 45: bool operator!=(...) - operator
  line 46: bool operator!=(...) - operator
  line 47: bool _NV_operator_notequal(...) - non-string reference arg
  line 48: operator bool(...) - unsupported return type
  line 58: bool operator<(...) - operator
  line 59: hand& operator=(...) - operator
  line 60: const hand& operator=(...) - operator
  line 61: const hand& operator=(...) - operator
  line 66: bool squadMatch(...) - unsupported arg type
*/

int handBinding::push(lua_State* L, const hand& h)
{
    hand* heapHand = new hand(h);
    return pushObject<hand>(L, heapHand, handBinding::getMetatableName());
}

int handBinding::gc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud) {
        delete (hand*)*ud;
        *ud = nullptr;
    }
    return 0;
}

int handBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hand object");
    return 1;
}

void handBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       handBinding::gc },
        { "__tostring", handBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "toString", handBinding::toString },
        { "fromString", handBinding::fromString },
        { "getCharacter", handBinding::getCharacter },
        { "getPlatoon", handBinding::getPlatoon },
        { "getActivePlatoon", handBinding::getActivePlatoon },
        { "getBuilding", handBinding::getBuilding },
        { "getItem", handBinding::getItem },
        { "getRootObject", handBinding::getRootObject },
        { "getRootObjectBase", handBinding::getRootObjectBase },
        { "getTown", handBinding::getTown },
        { "debugWhatHappenedToMe", handBinding::debugWhatHappenedToMe },
        { "setNull", handBinding::setNull },
        { "isNull", handBinding::isNull },
        { "isValid", handBinding::isValid },
        { "canCastToRootObject", handBinding::canCastToRootObject },
        { 0, 0 }
    };

    registerClass(
        L, 
        handBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, handBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "type", hand_get_type);
    registerGetter(L, "container", hand_get_container);
    registerGetter(L, "containerSerial", hand_get_containerSerial);
    registerGetter(L, "index", hand_get_index);
    registerGetter(L, "serial", hand_get_serial);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "type", hand_set_type);
    registerSetter(L, "container", hand_set_container);
    registerSetter(L, "containerSerial", hand_set_containerSerial);
    registerSetter(L, "index", hand_set_index);
    registerSetter(L, "serial", hand_set_serial);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua