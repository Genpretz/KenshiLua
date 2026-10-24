#include "pch.h"
#include "kenshi/AI/AIEventClass.h"
#include "AIEventClassBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static_assert(sizeof(AIEventClass) == 0x50, "AIEventClass size does not match the game");
static_assert(offsetof(AIEventClass, repeatTimer) == 0x4C, "AIEventClass::repeatTimer offset does not match the game");

static AIEventClass* getInstance(lua_State* L, int idx)
{
    return checkObject<AIEventClass>(L, idx, AIEventClassBinding::getMetatableName());
}

// --- Getters for AIEventClass ---
static int AIEventClass_get_target(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    return HandBinding::push(L, instance->target);
}

static int AIEventClass_get_sendWhoToDoIt(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    return HandBinding::push(L, instance->sendWhoToDoIt);
}

static int AIEventClass_get_repeatRate(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    lua_pushnumber(L, instance->repeatRate);
    return 1;
}

static int AIEventClass_get_repeatTimer(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    lua_pushnumber(L, instance->repeatTimer);
    return 1;
}

// --- Setters for AIEventClass ---
static int AIEventClass_set_target(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    instance->target = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AIEventClass_set_sendWhoToDoIt(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    instance->sendWhoToDoIt = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int AIEventClass_set_repeatRate(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    instance->repeatRate = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AIEventClass_set_repeatTimer(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");
    instance->repeatTimer = (float)luaL_checknumber(L, 2);
    return 0;
}

// Pure virtual; dispatches to the object's own implementation.
int AIEventClassBinding::update(lua_State* L)
{
    AIEventClass* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIEventClass is nil");

    instance->update();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 14-16: constructors and operator= - no address; AIEventClass is abstract
*/

int AIEventClassBinding::gc(lua_State* L)
{
    // Borrowed
    return 0;
}

int AIEventClassBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AIEventClass object");
    return 1;
}

void AIEventClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIEventClassBinding::gc },
        { "__tostring", AIEventClassBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "update", AIEventClassBinding::update },
        { 0, 0 }
    };

    registerClass(
        L,
        AIEventClassBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIEventClassBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "target", AIEventClass_get_target);
    registerGetter(L, "sendWhoToDoIt", AIEventClass_get_sendWhoToDoIt);
    registerGetter(L, "repeatRate", AIEventClass_get_repeatRate);
    registerGetter(L, "repeatTimer", AIEventClass_get_repeatTimer);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "target", AIEventClass_set_target);
    registerSetter(L, "sendWhoToDoIt", AIEventClass_set_sendWhoToDoIt);
    registerSetter(L, "repeatRate", AIEventClass_set_repeatRate);
    registerSetter(L, "repeatTimer", AIEventClass_set_repeatTimer);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
