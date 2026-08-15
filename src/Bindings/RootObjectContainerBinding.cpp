#include "pch.h"
#include "Bindings/RootObjectContainerBinding.h"
#include "Bindings/DataObjectContainerBinding.h"
#include "Bindings/FactoryCallbackInterfaceBinding.h"
#include "Bindings/GameDataBinding.h"
#include "Bindings/GameDataContainerBinding.h"
#include "Bindings/GameSaveStateBinding.h"
#include "Bindings/RootObjectBinding.h"
#include "Bindings/SpecificItemLoadFirstBinding.h"
#include "Bindings/Util/LektorBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

    static RootObjectContainer* getInstance(lua_State* L, int idx)
    {
        return checkObject<RootObjectContainer>(L, idx, RootObjectContainerBinding::getMetatableName());
    }

    // --- Getters for RootObjectContainer ---
    // --- Setters for RootObjectContainer ---
int RootObjectContainerBinding::addActiveObject(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        RootObject* b = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        bool result = instance->addActiveObject(b);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::_NV_addActiveObject(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        RootObject* b = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        bool result = instance->_NV_addActiveObject(b);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::removeObject(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        bool result = instance->removeObject(c);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::_NV_removeObject(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        RootObject* c = checkObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
        bool result = instance->_NV_removeObject(c);
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::update(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        bool result = instance->update();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::_NV_update(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        bool result = instance->_NV_update();
        lua_pushboolean(L, result ? 1 : 0);
        return 1;
    }

    int RootObjectContainerBinding::getThing(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        int id = (int)luaL_checkinteger(L, 2);
        RootObject* result = instance->getThing(id);
        return pushObject<RootObject>(L, result, RootObjectBinding::getMetatableName());
    }

    int RootObjectContainerBinding::getNumThings(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        int result = instance->getNumThings();
        lua_pushinteger(L, result);
        return 1;
    }

    int RootObjectContainerBinding::getThings(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        lektor<RootObject*>* result = instance->getThings();
        return pushObject<lektor<RootObject*>>(L, result, LektorPtrBinding<RootObject*>::metaName);
    }

    int RootObjectContainerBinding::loadToReality(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        bool skipSaveState = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 positionMoved;
        readVector3(L, 3, positionMoved);
        Ogre::Quaternion rotOffset;
        readQuaternion(L, 4, rotOffset);
        FactoryCallbackInterface* callback = checkObject<FactoryCallbackInterface>(L, 5, FactoryCallbackInterfaceBinding::getMetatableName());
        const std::string specificSID = luaL_checkstring(L, 6);
        GameDataContainer* externalContainer = checkObject<GameDataContainer>(L, 7, GameDataContainerBinding::getMetatableName());
        RootObjectContainer::SpecificItemLoadFirst* skipperClass = lua_isnoneornil(L, 8) ? nullptr : checkObject<RootObjectContainer::SpecificItemLoadFirst>(L, 8, SpecificItemLoadFirstBinding::getMetatableName());
        instance->loadToReality(skipSaveState, positionMoved, rotOffset, callback, specificSID, externalContainer, skipperClass);
        return 0;
    }

    int RootObjectContainerBinding::_NV_loadToReality(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        bool skipSaveState = lua_toboolean(L, 2) != 0;
        Ogre::Vector3 positionMoved;
        readVector3(L, 3, positionMoved);
        Ogre::Quaternion rotOffset;
        readQuaternion(L, 4, rotOffset);
        FactoryCallbackInterface* callback = checkObject<FactoryCallbackInterface>(L, 5, FactoryCallbackInterfaceBinding::getMetatableName());
        const std::string specificSID = luaL_checkstring(L, 6);
        GameDataContainer* externalContainer = checkObject<GameDataContainer>(L, 7, GameDataContainerBinding::getMetatableName());
        RootObjectContainer::SpecificItemLoadFirst* skipperClass = lua_isnoneornil(L, 8) ? nullptr : checkObject<RootObjectContainer::SpecificItemLoadFirst>(L, 8, SpecificItemLoadFirstBinding::getMetatableName());
        instance->_NV_loadToReality(skipSaveState, positionMoved, rotOffset, callback, specificSID, externalContainer, skipperClass);
        return 0;
    }

    int RootObjectContainerBinding::gc(lua_State* L)
    {
        return 0;
    }

    int RootObjectContainerBinding::tostring(lua_State* L)
    {
        lua_pushstring(L, "KenshiLua.RootObjectContainer object");
        return 1;
    }

    static int RootObjectContainer_get_things(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");
        return pushObject<lektor<RootObject*>>(L, &instance->things, LektorPtrBinding<RootObject*>::metaName);
    }

    static int RootObjectContainer_set_things(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");
        auto* val = LektorPtrBinding<RootObject*>::get(L, 2);
        if (!val) return luaL_error(L, "Argument 2 to set 'things' must be lektor<RootObject*>");
        instance->things = *val;
        return 0;
    }

int RootObjectContainerBinding::_NV_getSelectedObjects(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
        if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

        itemType type = (itemType)luaL_checkinteger(L, 3);
        bool selectedOnly = lua_toboolean(L, 4) != 0;

        instance->_NV_getSelectedObjects(*out, type, selectedOnly);
        return 0;
    }

    int RootObjectContainerBinding::_NV_loadInstance(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
        bool skipSaveState = lua_toboolean(L, 3) != 0;
        Ogre::Vector3 pos;
        readVector3(L, 4, pos);
        Ogre::Quaternion rot;
        readQuaternion(L, 5, rot);
        FactoryCallbackInterface* callback = lua_isnoneornil(L, 6) ? nullptr : checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
        Ogre::Vector3 positionMoved;
        readVector3(L, 7, positionMoved);

        instance->_NV_loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
        return 0;
    }

    int RootObjectContainerBinding::getSelectedObjects(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        lektor<RootObject*>* out = LektorPtrBinding<RootObject*>::get(L, 2);
        if (!out) return luaL_error(L, "Argument 2 must be a lektor<RootObject*>");

        itemType type = (itemType)luaL_checkinteger(L, 3);
        bool selectedOnly = lua_toboolean(L, 4) != 0;

        instance->getSelectedObjects(*out, type, selectedOnly);
        return 0;
    }

    int RootObjectContainerBinding::loadInstance(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        GameSaveState* state = checkObject<GameSaveState>(L, 2, GameSaveStateBinding::getMetatableName());
        bool skipSaveState = lua_toboolean(L, 3) != 0;
        Ogre::Vector3 pos;
        readVector3(L, 4, pos);
        Ogre::Quaternion rot;
        readQuaternion(L, 5, rot);
        FactoryCallbackInterface* callback = lua_isnoneornil(L, 6) ? nullptr : checkObject<FactoryCallbackInterface>(L, 6, FactoryCallbackInterfaceBinding::getMetatableName());
        Ogre::Vector3 positionMoved;
        readVector3(L, 7, positionMoved);

        instance->loadInstance(*state, skipSaveState, pos, rot, callback, positionMoved);
        return 0;
    }

    int RootObjectContainerBinding::serialiseThings(lua_State* L)
    {
        RootObjectContainer* instance = getInstance(L, 1);
        if (!instance) return luaL_error(L, "RootObjectContainer is nil");

        if (testObject<lektor<RootObject*>>(L, 2, LektorPtrBinding<RootObject*>::metaName) != nullptr)
        {
            lektor<RootObject*>* _things = LektorPtrBinding<RootObject*>::get(L, 2);
            GameData* gd = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
            GameDataContainer* source = lua_isnoneornil(L, 4) ? nullptr : checkObject<GameDataContainer>(L, 4, GameDataContainerBinding::getMetatableName());
            PosRotPair* offset = lua_isnoneornil(L, 5) ? nullptr : (PosRotPair*)lua_touserdata(L, 5);
            std::string mod = luaL_checkstring(L, 6);

            instance->serialiseThings(*_things, gd, source, offset, mod);
            return 0;
        }
        else
        {
            GameData* gd = lua_isnoneornil(L, 2) ? nullptr : checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
            GameDataContainer* source = lua_isnoneornil(L, 3) ? nullptr : checkObject<GameDataContainer>(L, 3, GameDataContainerBinding::getMetatableName());
            PosRotPair* offset = lua_isnoneornil(L, 4) ? nullptr : (PosRotPair*)lua_touserdata(L, 4);
            std::string mod = luaL_checkstring(L, 5);

            instance->serialiseThings(gd, source, offset, mod);
            return 0;
        }
    }

    void RootObjectContainerBinding::registerBinding(lua_State* L)
    {
        static const luaL_Reg meta[] = {
            { "__gc",       RootObjectContainerBinding::gc },
            { "__tostring", RootObjectContainerBinding::tostring },
            { 0, 0 }
        };

        static const luaL_Reg methods[] = {
            { "addActiveObject", RootObjectContainerBinding::addActiveObject },
            { "_NV_addActiveObject", RootObjectContainerBinding::_NV_addActiveObject },
            { "removeObject", RootObjectContainerBinding::removeObject },
            { "_NV_removeObject", RootObjectContainerBinding::_NV_removeObject },
            { "update", RootObjectContainerBinding::update },
            { "_NV_update", RootObjectContainerBinding::_NV_update },
            { "getThing", RootObjectContainerBinding::getThing },
            { "getNumThings", RootObjectContainerBinding::getNumThings },
            { "getThings", RootObjectContainerBinding::getThings },
            { "loadToReality", RootObjectContainerBinding::loadToReality },
            { "_NV_loadToReality", RootObjectContainerBinding::_NV_loadToReality },
            { "getSelectedObjects", RootObjectContainerBinding::getSelectedObjects },
            { "_NV_getSelectedObjects", RootObjectContainerBinding::_NV_getSelectedObjects },
            { "serialiseThings", RootObjectContainerBinding::serialiseThings },
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
        registerGetter(L, "things", RootObjectContainer_get_things);
        lua_setfield(L, -2, "__getters"); // Bind to metatable

        lua_newtable(L); // Create __setters table
        registerSetter(L, "things", RootObjectContainer_set_things);
        lua_setfield(L, -2, "__setters"); // Bind to metatable

        LektorPtrBinding<RootObject*>::registerBinding(L, "lektor<RootObject*>", RootObjectBinding::getMetatableName());

        lua_pop(L, 1); // Pop the metatable off the stack
    }

} // namespace KenshiLua