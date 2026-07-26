#include "pch.h"
#include "kenshi\PlayerInterface.h"
#include "AIOptionsBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

static AIOptions* getInstance(lua_State* L, int idx)
{
    return checkObject<AIOptions>(L, idx, AIOptionsBinding::getMetatableName());
}

// --- Getters for AIOptions ---
static int AIOptions_get_healAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->healAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_helpAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->helpAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_rescueAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->rescueAllies ? 1 : 0);
    return 1;
}

static int AIOptions_get_stayInBase(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->stayInBase ? 1 : 0);
    return 1;
}

static int AIOptions_get_feedAnimals(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->feedAnimals ? 1 : 0);
    return 1;
}

static int AIOptions_get_shareFood(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->shareFood ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoSleep(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->autoSleep ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoDitchItems(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->autoDitchItems ? 1 : 0);
    return 1;
}

static int AIOptions_get_autoSit(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->autoSit ? 1 : 0);
    return 1;
}

static int AIOptions_get_ejectEnemies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->ejectEnemies ? 1 : 0);
    return 1;
}

static int AIOptions_get_shootFirst(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    lua_pushboolean(L, instance->shootFirst ? 1 : 0);
    return 1;
}

// --- Setters for AIOptions ---
static int AIOptions_set_healAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->healAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_helpAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->helpAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_rescueAllies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->rescueAllies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_stayInBase(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->stayInBase = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_feedAnimals(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->feedAnimals = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_shareFood(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->shareFood = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoSleep(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->autoSleep = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoDitchItems(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->autoDitchItems = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_autoSit(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->autoSit = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_ejectEnemies(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->ejectEnemies = lua_toboolean(L, 2) != 0;
    return 0;
}

static int AIOptions_set_shootFirst(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");
    instance->shootFirst = lua_toboolean(L, 2) != 0;
    return 0;
}

int AIOptionsBinding::_CONSTRUCTOR(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");

    AIOptions* result = instance->_CONSTRUCTOR();
    return pushObject<AIOptions>(L, result, AIOptionsBinding::getMetatableName());
}

int AIOptionsBinding::load(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->load(data);
    return 0;
}

int AIOptionsBinding::save(lua_State* L)
{
    AIOptions* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AIOptions is nil");

    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    instance->save(data);
    return 0;
}

int AIOptionsBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AIOptionsBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AIOptions object");
    return 1;
}

void AIOptionsBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AIOptionsBinding::gc },
        { "__tostring", AIOptionsBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", AIOptionsBinding::_CONSTRUCTOR },
        { "load", AIOptionsBinding::load },
        { "save", AIOptionsBinding::save },
        { 0, 0 }
    };

    registerClass(
        L, 
        AIOptionsBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AIOptionsBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "healAllies", AIOptions_get_healAllies);
    registerGetter(L, "helpAllies", AIOptions_get_helpAllies);
    registerGetter(L, "rescueAllies", AIOptions_get_rescueAllies);
    registerGetter(L, "stayInBase", AIOptions_get_stayInBase);
    registerGetter(L, "feedAnimals", AIOptions_get_feedAnimals);
    registerGetter(L, "shareFood", AIOptions_get_shareFood);
    registerGetter(L, "autoSleep", AIOptions_get_autoSleep);
    registerGetter(L, "autoDitchItems", AIOptions_get_autoDitchItems);
    registerGetter(L, "autoSit", AIOptions_get_autoSit);
    registerGetter(L, "ejectEnemies", AIOptions_get_ejectEnemies);
    registerGetter(L, "shootFirst", AIOptions_get_shootFirst);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "healAllies", AIOptions_set_healAllies);
    registerSetter(L, "helpAllies", AIOptions_set_helpAllies);
    registerSetter(L, "rescueAllies", AIOptions_set_rescueAllies);
    registerSetter(L, "stayInBase", AIOptions_set_stayInBase);
    registerSetter(L, "feedAnimals", AIOptions_set_feedAnimals);
    registerSetter(L, "shareFood", AIOptions_set_shareFood);
    registerSetter(L, "autoSleep", AIOptions_set_autoSleep);
    registerSetter(L, "autoDitchItems", AIOptions_set_autoDitchItems);
    registerSetter(L, "autoSit", AIOptions_set_autoSit);
    registerSetter(L, "ejectEnemies", AIOptions_set_ejectEnemies);
    registerSetter(L, "shootFirst", AIOptions_set_shootFirst);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua