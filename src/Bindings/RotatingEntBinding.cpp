#include "pch.h"
#include <kenshi/PhysicsCollection.h>
#include "RotatingEntBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/GameDataBinding.h"

namespace KenshiLua
{

typedef PhysicsCollection::RotatingEnt RotatingEnt;

static RotatingEnt* getInstance(lua_State* L, int idx)
{
    return checkObject<RotatingEnt>(L, idx, RotatingEntBinding::getMetatableName());
}

// --- Getters for RotatingEnt ---
static int RotatingEnt_get_rotAxis(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    pushVector3(L, instance->rotAxis);
    return 1;
}

static int RotatingEnt_get_rotationSpeed(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->rotationSpeed);
    return 1;
}

static int RotatingEnt_get_rotationPower(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->rotationPower);
    return 1;
}

static int RotatingEnt_get_speedMin(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->speedMin);
    return 1;
}

static int RotatingEnt_get_speedMax(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->speedMax);
    return 1;
}

static int RotatingEnt_get_rotationBase(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    pushQuaternion(L, instance->rotationBase);
    return 1;
}

static int RotatingEnt_get_isRotating(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushboolean(L, instance->isRotating ? 1 : 0);
    return 1;
}

static int RotatingEnt_get_rotationSrc(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    pushQuaternion(L, instance->rotationSrc);
    return 1;
}

static int RotatingEnt_get_rotationDst(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    pushQuaternion(L, instance->rotationDst);
    return 1;
}

static int RotatingEnt_get_rotatingTime(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->rotatingTime);
    return 1;
}

static int RotatingEnt_get_rotationDuration(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->rotationDuration);
    return 1;
}

static int RotatingEnt_get_windSpeedRotationMin(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->windSpeedRotationMin);
    return 1;
}

static int RotatingEnt_get_windSpeedRotationMax(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->windSpeedRotationMax);
    return 1;
}

static int RotatingEnt_get_windSpeedRotationDanger(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    lua_pushnumber(L, instance->windSpeedRotationDanger);
    return 1;
}

// --- Setters for RotatingEnt ---
static int RotatingEnt_set_rotAxis(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    readVector3(L, 2, instance->rotAxis);
    return 0;
}

static int RotatingEnt_set_rotationSpeed(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->rotationSpeed = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_rotationPower(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->rotationPower = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_speedMin(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->speedMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_speedMax(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->speedMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_rotationBase(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    readQuaternion(L, 2, instance->rotationBase);
    return 0;
}

static int RotatingEnt_set_isRotating(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->isRotating = lua_toboolean(L, 2) != 0;
    return 0;
}

static int RotatingEnt_set_rotationSrc(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    readQuaternion(L, 2, instance->rotationSrc);
    return 0;
}

static int RotatingEnt_set_rotationDst(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    readQuaternion(L, 2, instance->rotationDst);
    return 0;
}

static int RotatingEnt_set_rotatingTime(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->rotatingTime = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_rotationDuration(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->rotationDuration = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_windSpeedRotationMin(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->windSpeedRotationMin = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_windSpeedRotationMax(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->windSpeedRotationMax = (float)luaL_checknumber(L, 2);
    return 0;
}

static int RotatingEnt_set_windSpeedRotationDanger(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");
    instance->windSpeedRotationDanger = (float)luaL_checknumber(L, 2);
    return 0;
}

int RotatingEntBinding::_DESTRUCTOR(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int RotatingEntBinding::update(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    float productionSpeed = (float)luaL_checknumber(L, 2);
    instance->update(productionSpeed);
    return 0;
}

int RotatingEntBinding::_NV_update(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    float productionSpeed = (float)luaL_checknumber(L, 2);
    instance->_NV_update(productionSpeed);
    return 0;
}

int RotatingEntBinding::updateAim(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    float speed = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 target;
    readVector3(L, 3, target);
    float result = instance->updateAim(speed, target);
    lua_pushnumber(L, result);
    return 1;
}

int RotatingEntBinding::_NV_updateAim(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    float speed = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 target;
    readVector3(L, 3, target);
    float result = instance->_NV_updateAim(speed, target);
    lua_pushnumber(L, result);
    return 1;
}

int RotatingEntBinding::isRotatingEnt(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    bool result = instance->isRotatingEnt();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RotatingEntBinding::_NV_isRotatingEnt(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    bool result = instance->_NV_isRotatingEnt();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RotatingEntBinding::getRotationPower(lua_State* L)
{
    RotatingEnt* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "RotatingEnt is nil");

    float result = instance->getRotationPower();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 137: RotatingEnt* _CONSTRUCTOR(...) - unsupported arg type
  line 147: void weatherUpdated(...) - unsupported arg type
  line 148: void _NV_weatherUpdated(...) - unsupported arg type
*/

/*
Skipped properties needing manual binding:
  line 150: rotAngle (Ogre::Radian) - unsupported type
  line 155: rotationFunction (BuildingRotation) - unsupported type
*/

int RotatingEntBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RotatingEntBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RotatingEnt object");
    return 1;
}

void RotatingEntBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RotatingEntBinding::gc },
        { "__tostring", RotatingEntBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", RotatingEntBinding::_DESTRUCTOR },
        { "update", RotatingEntBinding::update },
        { "_NV_update", RotatingEntBinding::_NV_update },
        { "updateAim", RotatingEntBinding::updateAim },
        { "_NV_updateAim", RotatingEntBinding::_NV_updateAim },
        { "isRotatingEnt", RotatingEntBinding::isRotatingEnt },
        { "_NV_isRotatingEnt", RotatingEntBinding::_NV_isRotatingEnt },
        { "getRotationPower", RotatingEntBinding::getRotationPower },
        { 0, 0 }
    };

    registerClass(
        L, 
        RotatingEntBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RotatingEntBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "rotAxis", RotatingEnt_get_rotAxis);
    registerGetter(L, "rotationSpeed", RotatingEnt_get_rotationSpeed);
    registerGetter(L, "rotationPower", RotatingEnt_get_rotationPower);
    registerGetter(L, "speedMin", RotatingEnt_get_speedMin);
    registerGetter(L, "speedMax", RotatingEnt_get_speedMax);
    registerGetter(L, "rotationBase", RotatingEnt_get_rotationBase);
    registerGetter(L, "isRotating", RotatingEnt_get_isRotating);
    registerGetter(L, "rotationSrc", RotatingEnt_get_rotationSrc);
    registerGetter(L, "rotationDst", RotatingEnt_get_rotationDst);
    registerGetter(L, "rotatingTime", RotatingEnt_get_rotatingTime);
    registerGetter(L, "rotationDuration", RotatingEnt_get_rotationDuration);
    registerGetter(L, "windSpeedRotationMin", RotatingEnt_get_windSpeedRotationMin);
    registerGetter(L, "windSpeedRotationMax", RotatingEnt_get_windSpeedRotationMax);
    registerGetter(L, "windSpeedRotationDanger", RotatingEnt_get_windSpeedRotationDanger);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "rotAxis", RotatingEnt_set_rotAxis);
    registerSetter(L, "rotationSpeed", RotatingEnt_set_rotationSpeed);
    registerSetter(L, "rotationPower", RotatingEnt_set_rotationPower);
    registerSetter(L, "speedMin", RotatingEnt_set_speedMin);
    registerSetter(L, "speedMax", RotatingEnt_set_speedMax);
    registerSetter(L, "rotationBase", RotatingEnt_set_rotationBase);
    registerSetter(L, "isRotating", RotatingEnt_set_isRotating);
    registerSetter(L, "rotationSrc", RotatingEnt_set_rotationSrc);
    registerSetter(L, "rotationDst", RotatingEnt_set_rotationDst);
    registerSetter(L, "rotatingTime", RotatingEnt_set_rotatingTime);
    registerSetter(L, "rotationDuration", RotatingEnt_set_rotationDuration);
    registerSetter(L, "windSpeedRotationMin", RotatingEnt_set_windSpeedRotationMin);
    registerSetter(L, "windSpeedRotationMax", RotatingEnt_set_windSpeedRotationMax);
    registerSetter(L, "windSpeedRotationDanger", RotatingEnt_set_windSpeedRotationDanger);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to PhysicsCollection::StaticEnt
    // setMetatableParent(L, RotatingEntBinding::getMetatableName(), PhysicsCollection::StaticEntBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua