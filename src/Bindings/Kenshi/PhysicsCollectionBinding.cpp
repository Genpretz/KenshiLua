#include "pch.h"
#include "kenshi\physicscollection.h"
#include "PhysicsCollectionBinding.h"
#include "Bindings/Kenshi/RotatingEntBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

namespace KenshiLua
{

static PhysicsCollection* getInstance(lua_State* L, int idx)
{
    return checkObject<PhysicsCollection>(L, idx, PhysicsCollectionBinding::getMetatableName());
}

// --- Getters for PhysicsCollection ---
// --- Setters for PhysicsCollection ---
int PhysicsCollectionBinding::findRotatingEnt(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    GameData* part = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    PhysicsCollection::RotatingEnt* result = instance->findRotatingEnt(part);
    return pushObject<PhysicsCollection::RotatingEnt>(L, result, RotatingEntBinding::getMetatableName());
}

int PhysicsCollectionBinding::getWindRotationPower(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    float result = instance->getWindRotationPower();
    lua_pushnumber(L, result);
    return 1;
}

int PhysicsCollectionBinding::getWindMillPart(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    PhysicsCollection::RotatingEnt* result = instance->getWindMillPart();
    return pushObject<PhysicsCollection::RotatingEnt>(L, result, RotatingEntBinding::getMetatableName());
}

int PhysicsCollectionBinding::isLoaded(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    bool result = instance->isLoaded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PhysicsCollectionBinding::setVisible(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    bool on = lua_toboolean(L, 2) != 0;
    instance->setVisible(on);
    return 0;
}

int PhysicsCollectionBinding::update(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    float speed = (float)luaL_checknumber(L, 2);
    instance->update(speed);
    return 0;
}

int PhysicsCollectionBinding::updateAimingType(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    float speed = (float)luaL_checknumber(L, 2);
    Ogre::Vector3 rotTarget;
    readVector3(L, 3, rotTarget);
    float result = instance->updateAimingType(speed, rotTarget);
    lua_pushnumber(L, result);
    return 1;
}

int PhysicsCollectionBinding::handleChanged(lua_State* L)
{
    PhysicsCollection* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PhysicsCollection is nil");

    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to handleChanged must be hand");
    instance->handleChanged(*h);
    return 0;
}

/*
LIGHTUSERDATA DEPENDENCIES:
  - PhysicsCollectionBinding::findRotatingEnt: PhysicsCollection::RotatingEnt* (unbound pointer)
  - PhysicsCollectionBinding::getWindMillPart: PhysicsCollection::RotatingEnt* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 190: staticEnts (lektor<PhysicsCollection::StaticEnt*>) - unsupported type
  line 191: parts (lektor<SimplePhysXEntity*>) - unsupported type
  line 192: lights (lektor<PhysicsCollection::LightEnt*>) - unsupported type
*/

int PhysicsCollectionBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PhysicsCollectionBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PhysicsCollection object");
    return 1;
}

void PhysicsCollectionBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PhysicsCollectionBinding::gc },
        { "__tostring", PhysicsCollectionBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "findRotatingEnt", PhysicsCollectionBinding::findRotatingEnt },
        { "getWindRotationPower", PhysicsCollectionBinding::getWindRotationPower },
        { "getWindMillPart", PhysicsCollectionBinding::getWindMillPart },
        { "isLoaded", PhysicsCollectionBinding::isLoaded },
        { "setVisible", PhysicsCollectionBinding::setVisible },
        { "handleChanged", PhysicsCollectionBinding::handleChanged },
        { "update", PhysicsCollectionBinding::update },
        { "updateAimingType", PhysicsCollectionBinding::updateAimingType },
        { 0, 0 }
    };

    registerClass(
        L, 
        PhysicsCollectionBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PhysicsCollectionBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, PhysicsCollectionBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua