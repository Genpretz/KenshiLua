#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"
#include "TargetInfoBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

// Lua owns every TargetInfo it creates or receives by value; copies use the exported copy constructor.
static_assert(sizeof(TargetInfo) == 0x30, "TargetInfo size does not match the game");
static_assert(offsetof(TargetInfo, pos) == 0x20, "TargetInfo::pos offset does not match the game");
static_assert(offsetof(TargetInfo, targetType) == 0x2C, "TargetInfo::targetType offset does not match the game");

static TargetInfo* getInstance(lua_State* L, int idx)
{
    return checkObject<TargetInfo>(L, idx, TargetInfoBinding::getMetatableName());
}

// --- Getters for TargetInfo ---
static int TargetInfo_get_what(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    return HandBinding::push(L, instance->what);
}

static int TargetInfo_get_pos(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    pushVector3(L, instance->pos);
    return 1;
}

static int TargetInfo_get_targetType(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    lua_pushinteger(L, (lua_Integer)instance->targetType);
    return 1;
}

// --- Setters for TargetInfo ---
static int TargetInfo_set_what(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    instance->what = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int TargetInfo_set_pos(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    Ogre::Vector3 value;
    if (!readVector3(L, 2, value)) return luaL_argerror(L, 2, "Vector3 table expected");
    instance->pos = value;
    return 0;
}

static int TargetInfo_set_targetType(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");
    instance->targetType = (TargetInfoType)luaL_checkinteger(L, 2);
    return 0;
}

// TargetInfo(), TargetInfo(const TargetInfo&), TargetInfo(const hand&), TargetInfo(int),
// TargetInfo(const hand&, const Ogre::Vector3&). TargetInfo(int) ignores its value.
int TargetInfoBinding::constructor(lua_State* L)
{
    int startIdx = lua_istable(L, 1) ? 2 : 1; // Called through the TargetInfo table's __call
    int numArgs = lua_gettop(L) - startIdx + 1;

    if (numArgs <= 0)
    {
        TargetInfo value;
        return pushValue<TargetInfo>(L, value, TargetInfoBinding::getMetatableName());
    }
    if (numArgs == 1)
    {
        if (lua_type(L, startIdx) == LUA_TNUMBER)
        {
            TargetInfo value((int)luaL_checkinteger(L, startIdx));
            return pushValue<TargetInfo>(L, value, TargetInfoBinding::getMetatableName());
        }
        TargetInfo* other = testObject<TargetInfo>(L, startIdx, TargetInfoBinding::getMetatableName());
        if (other)
            return pushValue<TargetInfo>(L, *other, TargetInfoBinding::getMetatableName());
        hand* h = checkObject<hand>(L, startIdx, HandBinding::getMetatableName());
        TargetInfo value(*h);
        return pushValue<TargetInfo>(L, value, TargetInfoBinding::getMetatableName());
    }

    hand* h = checkObject<hand>(L, startIdx, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, startIdx + 1, v)) return luaL_argerror(L, startIdx + 1, "Vector3 table expected");
    TargetInfo value(*h, v);
    return pushValue<TargetInfo>(L, value, TargetInfoBinding::getMetatableName());
}

int TargetInfoBinding::setupType(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    instance->setupType();
    return 0;
}

// operator=(const hand&); returns self.
int TargetInfoBinding::operator_assign(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    hand* p = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    *instance = *p;
    lua_settop(L, 1);
    return 1;
}

int TargetInfoBinding::operator_bool(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    bool result = instance->operator bool();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TargetInfoBinding::isTown(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    lua_pushboolean(L, instance->isTown() ? 1 : 0);
    return 1;
}

int TargetInfoBinding::isCharacter(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    lua_pushboolean(L, instance->isCharacter() ? 1 : 0);
    return 1;
}

int TargetInfoBinding::getTown(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    TownBase* result = instance->getTown();
    return pushObject<TownBase>(L, result, TownBaseBinding::getMetatableName());
}

int TargetInfoBinding::getCharacter(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    Character* result = instance->getCharacter();
    return pushObject<Character>(L, result, CharacterBinding::getMetatableName());
}

int TargetInfoBinding::getPositionForWaypoint(lua_State* L)
{
    TargetInfo* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TargetInfo is nil");

    Ogre::Vector3 from;
    if (!readVector3(L, 2, from)) return luaL_argerror(L, 2, "Vector3 table expected");
    Ogre::Vector3 result = instance->getPositionForWaypoint(from);
    pushVector3(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 61-71: _CONSTRUCTOR(...) - exposed through the TargetInfo(...) constructor instead
*/

int TargetInfoBinding::gc(lua_State* L)
{
    // Lua-created values use the owned metatable's __gc; others are borrowed from their owner
    return 0;
}

int TargetInfoBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TargetInfo object");
    return 1;
}

void TargetInfoBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TargetInfoBinding::gc },
        { "__tostring", TargetInfoBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setupType", TargetInfoBinding::setupType },
        { "operator_assign", TargetInfoBinding::operator_assign },
        { "operator_bool", TargetInfoBinding::operator_bool },
        { "isTown", TargetInfoBinding::isTown },
        { "isCharacter", TargetInfoBinding::isCharacter },
        { "getTown", TargetInfoBinding::getTown },
        { "getCharacter", TargetInfoBinding::getCharacter },
        { "getPositionForWaypoint", TargetInfoBinding::getPositionForWaypoint },
        { 0, 0 }
    };

    registerClass(
        L,
        TargetInfoBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TargetInfoBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "what", TargetInfo_get_what);
    registerGetter(L, "pos", TargetInfo_get_pos);
    registerGetter(L, "targetType", TargetInfo_get_targetType);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "what", TargetInfo_set_what);
    registerSetter(L, "pos", TargetInfo_set_pos);
    registerSetter(L, "targetType", TargetInfo_set_targetType);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack

    pushGlobalTable(L, "TargetInfo");
    registerConstructor(L, TargetInfoBinding::constructor);
    lua_setglobal(L, "TargetInfo");
}

} // namespace KenshiLua
