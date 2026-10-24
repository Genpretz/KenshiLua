#include "pch.h"
// Tasker.h must come before AI.h; see TaskDataBinding.cpp.
#include "kenshi/Tasker.h"
#include "kenshi/AI/AI.h"
#include "StateFunctionListBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/AI/AIBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static StateFunctionList* getInstance(lua_State* L, int idx)
{
    return checkObject<StateFunctionList>(L, idx, StateFunctionListBinding::getMetatableName());
}

int StateFunctionListBinding::isTrue(lua_State* L)
{
    StateFunctionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateFunctionList is nil");

    AI* ai = checkObject<AI>(L, 2, AIBinding::getMetatableName());
    StateType key = (StateType)luaL_checkinteger(L, 3);
    hand* h = checkObject<hand>(L, 4, HandBinding::getMetatableName());
    Ogre::Vector3 v;
    if (!readVector3(L, 5, v)) return luaL_argerror(L, 5, "Vector3 table expected");
    bool desired = lua_toboolean(L, 6) != 0;
    bool result = instance->isTrue(ai, key, *h, v, desired);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int StateFunctionListBinding::hasState(lua_State* L)
{
    StateFunctionList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "StateFunctionList is nil");

    StateType key = (StateType)luaL_checkinteger(L, 2);
    bool result = instance->hasState(key);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 12: add(StateType, bool (AI::*)(const hand&, const Ogre::Vector3&)) - takes an AI member-function pointer
  line 17-20: StateFunctionList(), _CONSTRUCTOR, ~StateFunctionList, _DESTRUCTOR - the engine's list is the static AI::stateFuncs

Skipped properties needing manual binding:
  line 15: stateFuncs (boost::unordered_map<StateType, bool (AI::*)(const hand&, const Ogre::Vector3&)>) - values are AI member-function pointers
*/

int StateFunctionListBinding::gc(lua_State* L)
{
    // Borrowed; the engine's list is the static AI::stateFuncs
    return 0;
}

int StateFunctionListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.StateFunctionList object");
    return 1;
}

void StateFunctionListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       StateFunctionListBinding::gc },
        { "__tostring", StateFunctionListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "isTrue", StateFunctionListBinding::isTrue },
        { "hasState", StateFunctionListBinding::hasState },
        { 0, 0 }
    };

    registerClass(
        L,
        StateFunctionListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, StateFunctionListBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
