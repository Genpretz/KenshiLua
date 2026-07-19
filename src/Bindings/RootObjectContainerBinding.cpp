#include "pch.h"
#include "kenshi\RootObject.h"
#include "RootObjectContainerBinding.h"
#include "RootObjectBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/Templates/LektorBinding.h"
#include "Bindings/DataObjectContainerBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/SpecificItemLoadFirstBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameSaveStateBinding.h"

namespace KenshiLua
{

static RootObjectContainer* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectContainer>(L, idx, RootObjectContainerBinding::getMetatableName());
}

// --- Getters for RootObjectContainer ---
static int RootObjectContainer_get_things(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");
    return pushObject<lektor<RootObject*>>(L, &b->things, LektorPtrBinding<RootObject*>::metaName);
}

// --- Setters for RootObjectContainer ---
static int RootObjectContainer_set_things(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");
    return luaL_error(L, "Read-only or unsupported setter type for things");
}

int RootObjectContainerBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    b->_DESTRUCTOR();
    return 0;
}

int RootObjectContainerBinding::update(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool result = b->update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::_NV_update(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool result = b->_NV_update();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::getThing(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    int id = (int)luaL_checkinteger(L, 2);
    RootObject* result = b->getThing(id);
    return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
}

int RootObjectContainerBinding::getNumThings(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    int result = b->getNumThings();
    lua_pushinteger(L, result);
    return 1;
}

int RootObjectContainerBinding::getThings(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* result = b->getThings();
    return pushObject<lektor<RootObject*>>(L, result, LektorPtrBinding<RootObject*>::metaName);
}

int RootObjectContainerBinding::getSelectedObjects(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;

    b->getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int RootObjectContainerBinding::_NV_getSelectedObjects(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
    if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

    itemType type = (itemType)luaL_checkinteger(L, 3);
    bool selectedOnly = lua_toboolean(L, 4) != 0;

    b->_NV_getSelectedObjects(*out, type, selectedOnly);
    return 0;
}

int RootObjectContainerBinding::_CONSTRUCTOR(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    if (lua_isnumber(L, 2))
    {
        DataObjectContainer::GroupType type = (DataObjectContainer::GroupType)luaL_checkinteger(L, 2);
        RootObjectContainer* result = b->_CONSTRUCTOR(type);
        return pushObject<RootObjectContainer>(L, result, RootObjectContainerBinding::getMetatableName());
    }
    else
    {
        DataObjectContainer* from = checkObject<DataObjectContainer>(L, 2, DataObjectContainerBinding::getMetatableName());
        RootObjectContainer* result = b->_CONSTRUCTOR(from);
        return pushObject<RootObjectContainer>(L, result, RootObjectContainerBinding::getMetatableName());
    }
}

int RootObjectContainerBinding::addActiveObject(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->addActiveObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::_NV_addActiveObject(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_NV_addActiveObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::removeObject(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->removeObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::_NV_removeObject(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    RootObject* obj = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    bool result = b->_NV_removeObject(obj);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int RootObjectContainerBinding::serialiseThings(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    if (testObject<lektor<RootObject*>>(L, 2, LektorPtrBinding<RootObject*>::metaName) != nullptr)
    {
        lektor<RootObject*>* _things = LektorPtrBinding<RootObject*>::get(L, 2);
        GameData* gd = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
        GameDataContainer* source = lua_isnoneornil(L, 4) ? nullptr : checkObject<GameDataContainer>(L, 4, GameDataContainerBinding::getMetatableName());
        PosRotPair* offset = lua_isnoneornil(L, 5) ? nullptr : (PosRotPair*)lua_touserdata(L, 5);
        std::string mod = luaL_checkstring(L, 6);

        b->serialiseThings(*_things, gd, source, offset, mod);
        return 0;
    }
    else
    {
        GameData* gd = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
        GameDataContainer* source = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameDataContainer>(L, 3, GameDataContainerBinding::getMetatableName());
        PosRotPair* offset = lua_isnoneornil(L, 4) ? nullptr : (PosRotPair*)lua_touserdata(L, 4);
        std::string mod = luaL_checkstring(L, 5);

        b->serialiseThings(gd, source, offset, mod);
        return 0;
    }
}

int RootObjectContainerBinding::loadToReality(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool skipSaveState = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 positionMoved;
    readVector3(L, 3, positionMoved);
    Ogre::Quaternion rotOffset;
    readQuaternion(L, 4, rotOffset);
    FactoryCallbackInterface* callback = lua_isnoneornil(L, 5) ? nullptr : checkObject<FactoryCallbackInterface>(L, 5, FactoryCallbackInterfaceBinding::getMetatableName());
    std::string specificSID = luaL_checkstring(L, 6);
    GameDataContainer* externalContainer = lua_isnoneornil(L, 7) ? nullptr : checkObject<GameDataContainer>(L, 7, GameDataContainerBinding::getMetatableName());
    RootObjectContainer::SpecificItemLoadFirst* skipperClass = lua_isnoneornil(L, 8) ? nullptr : checkObject<RootObjectContainer::SpecificItemLoadFirst>(L, 8, SpecificItemLoadFirstBinding::getMetatableName());

    b->loadToReality(skipSaveState, positionMoved, rotOffset, callback, specificSID, externalContainer, skipperClass);
    return 0;
}

int RootObjectContainerBinding::_NV_loadToReality(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    bool skipSaveState = lua_toboolean(L, 2) != 0;
    Ogre::Vector3 positionMoved;
    readVector3(L, 3, positionMoved);
    Ogre::Quaternion rotOffset;
    readQuaternion(L, 4, rotOffset);
    FactoryCallbackInterface* callback = lua_isnoneornil(L, 5) ? nullptr : checkObject<FactoryCallbackInterface>(L, 5, FactoryCallbackInterfaceBinding::getMetatableName());
    std::string specificSID = luaL_checkstring(L, 6);
    GameDataContainer* externalContainer = lua_isnoneornil(L, 7) ? nullptr : checkObject<GameDataContainer>(L, 7, GameDataContainerBinding::getMetatableName());
    RootObjectContainer::SpecificItemLoadFirst* skipperClass = lua_isnoneornil(L, 8) ? nullptr : checkObject<RootObjectContainer::SpecificItemLoadFirst>(L, 8, SpecificItemLoadFirstBinding::getMetatableName());

    b->_NV_loadToReality(skipSaveState, positionMoved, rotOffset, callback, specificSID, externalContainer, skipperClass);
    return 0;
}

int RootObjectContainerBinding::loadInstance(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool skipSaveState = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);
    FactoryCallbackInterface* callback = lua_isnoneornil(L, 6) ? nullptr : checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
    Ogre::Vector3 positionMoved;
    readVector3(L, 7, positionMoved);

    b->loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}

int RootObjectContainerBinding::_NV_loadInstance(lua_State* L)
{
    RootObjectContainer* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectContainer is nil");

    GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
    bool skipSaveState = lua_toboolean(L, 3) != 0;
    Ogre::Vector3 pos;
    readVector3(L, 4, pos);
    Ogre::Quaternion rot;
    readQuaternion(L, 5, rot);
    FactoryCallbackInterface* callback = lua_isnoneornil(L, 6) ? nullptr : checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
    Ogre::Vector3 positionMoved;
    readVector3(L, 7, positionMoved);

    b->_NV_loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
    return 0;
}

int RootObjectContainerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectContainerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObjectContainer object");
    return 1;
}

void RootObjectContainerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectContainerBinding::gc },
        { "__tostring", RootObjectContainerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_DESTRUCTOR", RootObjectContainerBinding::_DESTRUCTOR },
        { "update", RootObjectContainerBinding::update },
        { "_NV_update", RootObjectContainerBinding::_NV_update },
        { "getThing", RootObjectContainerBinding::getThing },
        { "getNumThings", RootObjectContainerBinding::getNumThings },
        { "getThings", RootObjectContainerBinding::getThings },
        { "getSelectedObjects", RootObjectContainerBinding::getSelectedObjects },
        { "_NV_getSelectedObjects", RootObjectContainerBinding::_NV_getSelectedObjects },
        { "_CONSTRUCTOR", RootObjectContainerBinding::_CONSTRUCTOR },
        { "addActiveObject", RootObjectContainerBinding::addActiveObject },
        { "_NV_addActiveObject", RootObjectContainerBinding::_NV_addActiveObject },
        { "removeObject", RootObjectContainerBinding::removeObject },
        { "_NV_removeObject", RootObjectContainerBinding::_NV_removeObject },
        { "serialiseThings", RootObjectContainerBinding::serialiseThings },
        { "loadToReality", RootObjectContainerBinding::loadToReality },
        { "_NV_loadToReality", RootObjectContainerBinding::_NV_loadToReality },
        { "loadInstance", RootObjectContainerBinding::loadInstance },
        { "_NV_loadInstance", RootObjectContainerBinding::_NV_loadInstance },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectContainerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectContainerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RootObjectContainer_get_things);
    lua_setfield(L, -2, "things");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObjectContainer_set_things);
    lua_setfield(L, -2, "things");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
