#include "pch.h"
#include "kenshi\CharMovement.h"
#include "FormationMoverBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/HandBinding.h"

namespace KenshiLua
{

static FormationMover* getB(lua_State* L, int idx)
{
    return checkObject<FormationMover>(L, idx, FormationMoverBinding::getMetatableName());
}

// --- Getters for FormationMover ---
static int FormationMover_get_me(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    return pushObject<Character>(L, b->me, CharacterBinding::getMetatableName());
}

static int FormationMover_get_destination(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    pushVector3(L, b->destination);
    return 1;
}

static int FormationMover_get_direction(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    pushVector3(L, b->direction);
    return 1;
}

static int FormationMover_get_movementTarget(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    return handBinding::push(L, b->movementTarget);
}

static int FormationMover_get_currentFormationID(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    lua_pushinteger(L, b->currentFormationID);
    return 1;
}

// --- Setters for FormationMover ---
static int FormationMover_set_me(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    return luaL_error(L, "Read-only or unsupported setter type for me");
}

static int FormationMover_set_destination(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    readVector3(L, 2, b->destination);
    return 0;
}

static int FormationMover_set_direction(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    readVector3(L, 2, b->direction);
    return 0;
}

static int FormationMover_set_movementTarget(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    hand* val = checkObject<hand>(L, 2, handBinding::getMetatableName());
    b->movementTarget = *val;
    return 0;
}

static int FormationMover_set_currentFormationID(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");
    b->currentFormationID = (int)luaL_checkinteger(L, 2);
    return 0;
}

int FormationMoverBinding::_DESTRUCTOR(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");

    b->_DESTRUCTOR();
    return 0;
}

int FormationMoverBinding::update(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");

    b->update();
    return 0;
}

int FormationMoverBinding::stopFormationMode(lua_State* L)
{
    FormationMover* b = getB(L, 1);
    if (!b) return luaL_error(L, "FormationMover is nil");

    b->stopFormationMode();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 351: FormationMover* _CONSTRUCTOR(...) - unsupported return type
  line 358: void getSpeeds(...) - non-string reference arg
  line 359: void setFormationMode(...) - unsupported arg type
*/

int FormationMoverBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int FormationMoverBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.FormationMover object");
    return 1;
}

void FormationMoverBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       FormationMoverBinding::gc },
        { "__tostring", FormationMoverBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", FormationMoverBinding::_DESTRUCTOR },
        { "update", FormationMoverBinding::update },
        { "stopFormationMode", FormationMoverBinding::stopFormationMode },
        { 0, 0 }
    };

    registerClass(
        L, 
        FormationMoverBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, FormationMoverBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, FormationMover_get_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FormationMover_get_destination);
    lua_setfield(L, -2, "destination");
    lua_pushcfunction(L, FormationMover_get_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, FormationMover_get_movementTarget);
    lua_setfield(L, -2, "movementTarget");
    lua_pushcfunction(L, FormationMover_get_currentFormationID);
    lua_setfield(L, -2, "currentFormationID");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, FormationMover_set_me);
    lua_setfield(L, -2, "me");
    lua_pushcfunction(L, FormationMover_set_destination);
    lua_setfield(L, -2, "destination");
    lua_pushcfunction(L, FormationMover_set_direction);
    lua_setfield(L, -2, "direction");
    lua_pushcfunction(L, FormationMover_set_movementTarget);
    lua_setfield(L, -2, "movementTarget");
    lua_pushcfunction(L, FormationMover_set_currentFormationID);
    lua_setfield(L, -2, "currentFormationID");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua