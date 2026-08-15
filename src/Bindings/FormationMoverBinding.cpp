#include "pch.h"
#include "kenshi\CharMovement.h"
#include "FormationMoverBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Util/HandBinding.h"

namespace KenshiLua
{

static FormationMover* getInstance(lua_State* L, int idx)
{
    return checkObject<FormationMover>(L, idx, FormationMoverBinding::getMetatableName());
}

// --- Getters for FormationMover ---
static int FormationMover_get_me(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    return pushObject<Character>(L, instance->me, CharacterBinding::getMetatableName());
}

static int FormationMover_get_destination(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    pushVector3(L, instance->destination);
    return 1;
}

static int FormationMover_get_direction(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    pushVector3(L, instance->direction);
    return 1;
}

static int FormationMover_get_movementTarget(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    return HandBinding::push(L, instance->movementTarget);
}

static int FormationMover_get_currentFormationID(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    lua_pushinteger(L, instance->currentFormationID);
    return 1;
}

// --- Setters for FormationMover ---
static int FormationMover_set_me(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    instance->me = lua_isnoneornil(L, 2) ? nullptr : checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    return 0;
}

static int FormationMover_set_destination(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    readVector3(L, 2, instance->destination);
    return 0;
}

static int FormationMover_set_direction(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    readVector3(L, 2, instance->direction);
    return 0;
}

static int FormationMover_set_movementTarget(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    instance->movementTarget = *checkObject<hand>(L, 2, HandBinding::getMetatableName());
    return 0;
}

static int FormationMover_set_currentFormationID(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");
    instance->currentFormationID = (int)luaL_checkinteger(L, 2);
    return 0;
}

int FormationMoverBinding::update(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");

    instance->update();
    return 0;
}

int FormationMoverBinding::stopFormationMode(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");

    instance->stopFormationMode();
    return 0;
}

int FormationMoverBinding::getSpeeds(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");

    Ogre::Vector3 motion;
    readVector3(L, 2, motion);
    float frameTime = (float)luaL_checknumber(L, 3);
    float speed = 0.0f;
    float strafeSpeed = 0.0f;
    instance->getSpeeds(speed, strafeSpeed, motion, frameTime);
    lua_pushnumber(L, speed);
    lua_pushnumber(L, strafeSpeed);
    return 2;
}

int FormationMoverBinding::setFormationMode(lua_State* L)
{
    FormationMover* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "FormationMover is nil");

    hand* target = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    instance->setFormationMode(*target);
    return 0;
}

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
        { "update", FormationMoverBinding::update },
        { "getSpeeds", FormationMoverBinding::getSpeeds },
        { "setFormationMode", FormationMoverBinding::setFormationMode },
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
    registerGetter(L, "me", FormationMover_get_me);
    registerGetter(L, "destination", FormationMover_get_destination);
    registerGetter(L, "direction", FormationMover_get_direction);
    registerGetter(L, "movementTarget", FormationMover_get_movementTarget);
    registerGetter(L, "currentFormationID", FormationMover_get_currentFormationID);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "me", FormationMover_set_me);
    registerSetter(L, "destination", FormationMover_set_destination);
    registerSetter(L, "direction", FormationMover_set_direction);
    registerSetter(L, "movementTarget", FormationMover_set_movementTarget);
    registerSetter(L, "currentFormationID", FormationMover_set_currentFormationID);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua