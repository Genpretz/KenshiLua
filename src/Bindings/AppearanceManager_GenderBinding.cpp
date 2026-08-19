#include "pch.h"
#include "Bindings/AppearanceManager_GenderBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceManager::Gender* getInstance(lua_State* L, int idx)
{
    return checkObject<AppearanceManager::Gender>(L, idx, AppearanceManager_GenderBinding::getMetatableName());
}

// --- Methods ---
int AppearanceManager_GenderBinding::isMale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    lua_pushboolean(L, inst->isMale() ? 1 : 0);
    return 1;
}

int AppearanceManager_GenderBinding::isFemale(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    lua_pushboolean(L, inst->isFemale() ? 1 : 0);
    return 1;
}

int AppearanceManager_GenderBinding::toString(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    std::string result = inst->toString();
    lua_pushlstring(L, result.c_str(), result.size());
    return 1;
}

int AppearanceManager_GenderBinding::getValue(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    AppearanceManager::Gender::Enum result = inst->getValue();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

// --- Getters for Gender ---
static int Gender_get_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    lua_pushinteger(L, (lua_Integer)inst->value);
    return 1;
}

// --- Setters for Gender ---
static int Gender_set_value(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (!inst) return luaL_error(L, "AppearanceManager::Gender is nil");
    inst->value = (AppearanceManager::Gender::Enum)luaL_checkinteger(L, 2);
    return 0;
}

int AppearanceManager_GenderBinding::gc(lua_State* L)
{
    return 0;
}

int AppearanceManager_GenderBinding::tostring(lua_State* L)
{
    auto* inst = getInstance(L, 1);
    if (inst)
    {
        std::string s = inst->toString();
        lua_pushlstring(L, s.c_str(), s.size());
        return 1;
    }
    lua_pushstring(L, "KenshiLua.AppearanceManager_Gender object");
    return 1;
}

int AppearanceManager_GenderBinding::operator_eq(lua_State* L)
{
    auto* a = getInstance(L, 1);
    auto* b = getInstance(L, 2);
    lua_pushboolean(L, (a && b && (a->value == b->value)) ? 1 : 0);
    return 1;
}

void AppearanceManager_GenderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__eq",       AppearanceManager_GenderBinding::operator_eq },
        { "__gc",       AppearanceManager_GenderBinding::gc },
        { "__tostring", AppearanceManager_GenderBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "isMale",     AppearanceManager_GenderBinding::isMale },
        { "isFemale",   AppearanceManager_GenderBinding::isFemale },
        { "toString",   AppearanceManager_GenderBinding::toString },
        { "getValue",   AppearanceManager_GenderBinding::getValue },
        { 0, 0 }
    };

    registerClass(L, getMetatableName(), meta, methods, genericPropertyIndex, genericPropertyNewIndex);

    luaL_getmetatable(L, getMetatableName());
    lua_newtable(L); // __getters
    registerGetter(L, "value", Gender_get_value);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L); // __setters
    registerSetter(L, "value", Gender_set_value);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);
}

} // namespace KenshiLua
