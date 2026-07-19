#include "pch.h"
#include "kenshi\Appearance.h"
#include "AppearanceAnimalBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AppearanceAnimal* getB(lua_State* L, int idx)
{
    return checkObject<AppearanceAnimal>(L, idx, AppearanceAnimalBinding::getMetatableName());
}

// --- Getters for AppearanceAnimal ---
// --- Setters for AppearanceAnimal ---
// --- Methods for AppearanceAnimal ---
int AppearanceAnimalBinding::_DESTRUCTOR(lua_State* L)
{
    AppearanceAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceAnimal is nil");

    b->_DESTRUCTOR();
    return 0;
}

int AppearanceAnimalBinding::createBody(lua_State* L)
{
    AppearanceAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceAnimal is nil");

    b->createBody();
    return 0;
}

int AppearanceAnimalBinding::_NV_createBody(lua_State* L)
{
    AppearanceAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceAnimal is nil");

    b->_NV_createBody();
    return 0;
}

int AppearanceAnimalBinding::updateCharaterTexture(lua_State* L)
{
    AppearanceAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceAnimal is nil");

    b->updateCharaterTexture();
    return 0;
}

int AppearanceAnimalBinding::_NV_updateCharaterTexture(lua_State* L)
{
    AppearanceAnimal* b = getB(L, 1);
    if (!b) return luaL_error(L, "AppearanceAnimal is nil");

    b->_NV_updateCharaterTexture();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 252: AppearanceAnimal* _CONSTRUCTOR(...) - unsupported return type
*/

int AppearanceAnimalBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AppearanceAnimalBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AppearanceAnimal object");
    return 1;
}

void AppearanceAnimalBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AppearanceAnimalBinding::gc },
        { "__tostring", AppearanceAnimalBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", AppearanceAnimalBinding::_DESTRUCTOR },
        { "createBody", AppearanceAnimalBinding::createBody },
        { "_NV_createBody", AppearanceAnimalBinding::_NV_createBody },
        { "updateCharaterTexture", AppearanceAnimalBinding::updateCharaterTexture },
        { "_NV_updateCharaterTexture", AppearanceAnimalBinding::_NV_updateCharaterTexture },
        { 0, 0 }
    };

    registerClass(
        L, 
        AppearanceAnimalBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AppearanceAnimalBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
