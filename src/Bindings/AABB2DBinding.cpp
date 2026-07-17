#include "pch.h"
#include <kenshi/ZoneManager.h>
#include "AABB2DBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static AABB2D* getInstance(lua_State* L, int idx)
{
    return checkObject<AABB2D>(L, idx, AABB2DBinding::getMetatableName());
}

// --- Getters for AABB2D ---
static int AABB2D_get_x(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    lua_pushnumber(L, instance->x);
    return 1;
}

static int AABB2D_get_y(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    lua_pushnumber(L, instance->y);
    return 1;
}

static int AABB2D_get_x2(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    lua_pushnumber(L, instance->x2);
    return 1;
}

static int AABB2D_get_y2(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    lua_pushnumber(L, instance->y2);
    return 1;
}

// --- Setters for AABB2D ---
static int AABB2D_set_x(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    instance->x = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AABB2D_set_y(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    instance->y = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AABB2D_set_x2(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    instance->x2 = (float)luaL_checknumber(L, 2);
    return 0;
}

static int AABB2D_set_y2(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");
    instance->y2 = (float)luaL_checknumber(L, 2);
    return 0;
}

int AABB2DBinding::setNull(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");

    instance->setNull();
    return 0;
}

int AABB2DBinding::pointWithin(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");

    Ogre::Vector3 v;
    readVector3(L, 2, v);
    bool result = instance->pointWithin(v);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int AABB2DBinding::inflate(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");

    float amount = (float)luaL_checknumber(L, 2);
    instance->inflate(amount);
    return 0;
}

int AABB2DBinding::sizeX(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");

    float result = instance->sizeX();
    lua_pushnumber(L, result);
    return 1;
}

int AABB2DBinding::sizeY(lua_State* L)
{
    AABB2D* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AABB2D is nil");

    float result = instance->sizeY();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 18: AABB2D* _CONSTRUCTOR(...) - overloaded method
  line 23: AABB2D* _CONSTRUCTOR(...) - overloaded method
  line 43: bool intersects(...) - overloaded method
  line 44: bool intersects(...) - overloaded method
  line 45: bool intersects(...) - overloaded method
  line 46: Ogre::Vector2 intersects2(...) - unsupported return type
*/

int AABB2DBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int AABB2DBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AABB2D object");
    return 1;
}

void AABB2DBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AABB2DBinding::gc },
        { "__tostring", AABB2DBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "setNull", AABB2DBinding::setNull },
        { "pointWithin", AABB2DBinding::pointWithin },
        { "inflate", AABB2DBinding::inflate },
        { "sizeX", AABB2DBinding::sizeX },
        { "sizeY", AABB2DBinding::sizeY },
        { 0, 0 }
    };

    registerClass(
        L, 
        AABB2DBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AABB2DBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, AABB2D_get_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, AABB2D_get_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, AABB2D_get_x2);
    lua_setfield(L, -2, "x2");
    lua_pushcfunction(L, AABB2D_get_y2);
    lua_setfield(L, -2, "y2");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, AABB2D_set_x);
    lua_setfield(L, -2, "x");
    lua_pushcfunction(L, AABB2D_set_y);
    lua_setfield(L, -2, "y");
    lua_pushcfunction(L, AABB2D_set_x2);
    lua_setfield(L, -2, "x2");
    lua_pushcfunction(L, AABB2D_set_y2);
    lua_setfield(L, -2, "y2");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua