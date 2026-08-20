#include "pch.h"

#include "Bindings/Util/HandBinding.h"

#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/ItemBinding.h"
#include "Bindings/PlatoonBinding.h"
#include "Bindings/RootObjectBaseBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/TownBaseBinding.h"

#include "Lua/BindingHelpers.h"

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

static hand* get(lua_State* L, int idx)
{
    return checkObject<hand>(L, idx, HandBinding::getMetatableName());
}

// --- Getters for hand ---
static int hand_get_type(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, (lua_Integer)instance->type);
    return 1;
}

static int hand_get_container(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->container);
    return 1;
}

static int hand_get_containerSerial(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->containerSerial);
    return 1;
}

static int hand_get_index(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->index);
    return 1;
}

static int hand_get_serial(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    lua_pushinteger(L, instance->serial);
    return 1;
}

// --- Setters for hand ---
static int hand_set_type(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->type = (itemType)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_container(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->container = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_containerSerial(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->containerSerial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_index(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->index = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int hand_set_serial(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");
    instance->serial = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

int HandBinding::toString(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    std::string result = instance->toString();
    lua_pushstring(L, result.c_str());
    return 1;
}

int HandBinding::fromString(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    const std::string str = luaL_checkstring(L, 2);
    instance->fromString(str);
    return 0;
}

int HandBinding::getCharacter(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int HandBinding::getPlatoon(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Platoon* result = instance->getPlatoon();
    return pushObject<Platoon>(L, result, PlatoonBinding::getMetatableName());
}

int HandBinding::getActivePlatoon(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    ActivePlatoon* result = instance->getActivePlatoon();
    return pushObject<ActivePlatoon>(L, result, ActivePlatoonBinding::getMetatableName());
}

int HandBinding::getBuilding(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Building* result = instance->getBuilding();
    return pushObject<Building>(L, result, BuildingBinding::getMetatableName());
}

int HandBinding::getItem(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    Item* result = instance->getItem();
    return pushObject<Item>(L, result, ItemBinding::getMetatableName());
}

int HandBinding::getRootObject(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    RootObject* result = instance->getRootObject();
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int HandBinding::getRootObjectBase(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    RootObjectBase* result = instance->getRootObjectBase();
    return pushObject<RootObjectBase>(L, result, RootObjectBaseBinding::getMetatableName());
}

int HandBinding::getTown(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    TownBase* result = instance->getTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int HandBinding::debugWhatHappenedToMe(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    std::string result = instance->debugWhatHappenedToMe();
    lua_pushstring(L, result.c_str());
    return 1;
}

int HandBinding::setNull(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    instance->setNull();
    return 0;
}

int HandBinding::isNull(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->isNull();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HandBinding::isValid(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->isValid();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HandBinding::canCastToRootObject(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    bool result = instance->canCastToRootObject();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HandBinding::squadMatch(lua_State* L)
{
    hand* instance = get(L, 1);
    if (!instance) return luaL_error(L, "hand is nil");

    hand* other = get(L, 2);
    if (!other) return luaL_error(L, "Argument 2 to squadMatch must be a hand");

    bool result = instance->squadMatch(*other);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int HandBinding::eq(lua_State* L)
{
    hand* a = get(L, 1);
    hand* b = get(L, 2);
    if (!a || !b) {
        lua_pushboolean(L, a == b ? 1 : 0);
        return 1;
    }
    lua_pushboolean(L, (*a == *b) ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 48: operator bool(...) - unsupported return type
  line 58: bool operator<(...) - operator
  line 59: hand& operator=(...) - operator
  line 60: const hand& operator=(...) - operator
  line 61: const hand& operator=(...) - operator
*/

int HandBinding::push(lua_State* L, const hand& h)
{
    hand* heapHand = new hand(h);
    return pushObject<hand>(L, heapHand, HandBinding::getMetatableName());
}

int HandBinding::gc(lua_State* L)
{
    void** ud = (void**)lua_touserdata(L, 1);
    if (ud && *ud) {
        delete (hand*)*ud;
        *ud = nullptr;
    }
    return 0;
}

int HandBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.hand object");
    return 1;
}

void HandBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HandBinding::gc },
        { "__tostring", HandBinding::tostring },
        { "__eq",       HandBinding::eq },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "toString", HandBinding::toString },
        { "fromString", HandBinding::fromString },
        { "getCharacter", HandBinding::getCharacter },
        { "getPlatoon", HandBinding::getPlatoon },
        { "getActivePlatoon", HandBinding::getActivePlatoon },
        { "getBuilding", HandBinding::getBuilding },
        { "getItem", HandBinding::getItem },
        { "getRootObject", HandBinding::getRootObject },
        { "getRootObjectBase", HandBinding::getRootObjectBase },
        { "getTown", HandBinding::getTown },
        { "debugWhatHappenedToMe", HandBinding::debugWhatHappenedToMe },
        { "setNull", HandBinding::setNull },
        { "isNull", HandBinding::isNull },
        { "isValid", HandBinding::isValid },
        { "canCastToRootObject", HandBinding::canCastToRootObject },
        { "squadMatch", HandBinding::squadMatch },
        { 0, 0 }
    };

    registerClass(
        L, 
        HandBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HandBinding::getMetatableName());
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