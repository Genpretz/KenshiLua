#include "pch.h"
#include <kenshi/Building/LightBuilding.h>
#include "LightBuildingBinding.h"
#include "UseableStuffBinding.h"
#include "Bindings/Util/HandBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static LightBuilding* getInstance(lua_State* L, int idx)
{
    return checkObject<LightBuilding>(L, idx, LightBuildingBinding::getMetatableName());
}

// --- Getters for LightBuilding ---
static int LightBuilding_get_mountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");
    return HandBinding::push(L, instance->mountedBuilding);
}

// --- Setters for LightBuilding ---
static int LightBuilding_set_mountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");
    hand* val = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!val) return luaL_error(L, "Argument 2 to set_mountedBuilding must be a hand");
    instance->mountedBuilding = *val;
    return 0;
}

// --- Methods for LightBuilding
int LightBuildingBinding::createPhysical(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_createPhysical(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->_NV_createPhysical();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::getMouseCursor(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    CursorType result = instance->getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int LightBuildingBinding::_NV_getMouseCursor(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    CursorType result = instance->_NV_getMouseCursor();
    lua_pushinteger(L, (lua_Integer)result);
    return 1;
}

int LightBuildingBinding::needPowerRightNow(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::_NV_needPowerRightNow(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    bool result = instance->_NV_needPowerRightNow();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int LightBuildingBinding::getPositionMarker(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int LightBuildingBinding::_NV_getPositionMarker(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    Ogre::Vector3 currentPosition;
    readVector3(L, 2, currentPosition);
    Ogre::Vector3 result = instance->_NV_getPositionMarker(currentPosition);
    pushVector3(L, result);
    return 1;
}

int LightBuildingBinding::serialise(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int LightBuildingBinding::_NV_serialise(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    GameDataContainer* container = checkObject<GameDataContainer>(L, 2, GameDataContainerBinding::getMetatableName());
    GameData* refList = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    PosRotPair* offset = (PosRotPair*)lua_touserdata(L, 4);

    GameSaveState result = instance->_NV_serialise(container, refList, offset);
    return pushValue<GameSaveState>(L, result, GameSaveStateBinding::getMetatableName());
}

int LightBuildingBinding::loadFromSerialise(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    if (!state) return luaL_error(L, "Argument 2 to loadFromSerialise must be a GameSaveState");

    instance->loadFromSerialise(state);
    return 0;
}

int LightBuildingBinding::_NV_loadFromSerialise(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    if (!state) return luaL_error(L, "Argument 2 to _NV_loadFromSerialise must be a GameSaveState");

    instance->_NV_loadFromSerialise(state);
    return 0;
}

int LightBuildingBinding::getMountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    hand result = instance->getMountedBuilding();
    return pushValue<hand>(L, result, HandBinding::getMetatableName());
}

int LightBuildingBinding::_NV_getMountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    hand result = instance->_NV_getMountedBuilding();
    return pushValue<hand>(L, result, HandBinding::getMetatableName());
}

int LightBuildingBinding::setMountedBuilding(lua_State* L)
{
    LightBuilding* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "LightBuilding is nil");

    Building* b = checkObject<Building>(L, 2, BuildingBinding::getMetatableName());
    if (!b) return luaL_error(L, "Argument 2 to setMountedBuilding must be a Building");

    instance->setMountedBuilding(b);
    return 0;
}

int LightBuildingBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int LightBuildingBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.LightBuilding object");
    return 1;
}

void LightBuildingBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       LightBuildingBinding::gc },
        { "__tostring", LightBuildingBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "createPhysical", LightBuildingBinding::createPhysical },
        { "_NV_createPhysical", LightBuildingBinding::_NV_createPhysical },
        { "getMouseCursor", LightBuildingBinding::getMouseCursor },
        { "_NV_getMouseCursor", LightBuildingBinding::_NV_getMouseCursor },
        { "needPowerRightNow", LightBuildingBinding::needPowerRightNow },
        { "_NV_needPowerRightNow", LightBuildingBinding::_NV_needPowerRightNow },
        { "getPositionMarker", LightBuildingBinding::getPositionMarker },
        { "_NV_getPositionMarker", LightBuildingBinding::_NV_getPositionMarker },
        { "serialise", LightBuildingBinding::serialise },
        { "_NV_serialise", LightBuildingBinding::_NV_serialise },
        { "loadFromSerialise", LightBuildingBinding::loadFromSerialise },
        { "_NV_loadFromSerialise", LightBuildingBinding::_NV_loadFromSerialise },
        { "getMountedBuilding", LightBuildingBinding::getMountedBuilding },
        { "_NV_getMountedBuilding", LightBuildingBinding::_NV_getMountedBuilding },
        { "setMountedBuilding", LightBuildingBinding::setMountedBuilding },
        { 0, 0 }
    };

    registerClass(
        L, 
        LightBuildingBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, LightBuildingBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, LightBuilding_get_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, LightBuilding_set_mountedBuilding);
    lua_setfield(L, -2, "mountedBuilding");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to UseableStuff
    // Inheritance wired in RegisterBindings.cpp::registerInheritance()
    // setMetatableParent(L, LightBuildingBinding::getMetatableName(), UseableStuffBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
