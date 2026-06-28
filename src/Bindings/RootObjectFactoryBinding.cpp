#include "pch.h"
#include "kenshi\RootObjectFactory.h"
#include "RootObjectFactoryBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static RootObjectFactory* getB(lua_State* L, int idx)
{
    return checkObject<RootObjectFactory>(L, idx, RootObjectFactoryBinding::getMetatableName());
}

// --- Getters for RootObjectFactory ---
static int RootObjectFactory_get_todoMutex(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    lua_pushnil(L);
    return 1;
}

static int RootObjectFactory_get_todoList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    // TODO: Unsupported type for todoList (std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> >)
    return luaL_error(L, "Unsupported property 'todoList' (type: std::deque<RootObjectFactory::CreatelistItem*, std::allocator<RootObjectFactory::CreatelistItem*> >)");
}

// --- Setters for RootObjectFactory ---
static int RootObjectFactory_set_todoMutex(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for todoMutex");
}

static int RootObjectFactory_set_todoList(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");
    return luaL_error(L, "Read-only or unsupported setter type for todoList");
}

int RootObjectFactoryBinding::mainThreadUpdate(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    b->mainThreadUpdate();
    return 0;
}

int RootObjectFactoryBinding::_DESTRUCTOR(lua_State* L)
{
    RootObjectFactory* b = getB(L, 1);
    if (!b) return luaL_error(L, "RootObjectFactory is nil");

    b->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 36: RootObjectBase* create(...) - unsupported arg type
  line 37: Building* createBuilding(...) - unsupported arg type
  line 38: LocationNode* createLocationNode(...) - unsupported return type
  line 39: Item* createItem(...) - overloaded method
  line 40: Item* createItem(...) - overloaded method
  line 41: Item* copyItem(...) - unsupported arg type
  line 42: GameData* chooseDataFromList(...) - unsupported arg type
  line 43: const GameDataReference* chooseDataFromListWithVals(...) - unsupported return type
  line 44: TripleInt getValsFromDataInList(...) - unsupported return type
  line 45: void createCharacterForBuilding(...) - unsupported arg type
  line 46: RootObject* createRandomCharacter(...) - unsupported arg type
  line 47: GameSaveState createRandomUnloadedCharacter(...) - unsupported return type
  line 48: Platoon* createRandomSquad(...) - unsupported arg type
  line 49: Platoon* createRandomUnloadedSquad(...) - unsupported arg type
  line 51: void populateBuilding(...) - unsupported arg type
  line 52: void chooseMyClothing(...) - static method
  line 53: GameData* _chooseClothingItemFromList(...) - static method
  line 73: RootObjectBase* process(...) - pointer arg
  line 76: RootObjectFactory* _CONSTRUCTOR(...) - unsupported return type
*/

int RootObjectFactoryBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int RootObjectFactoryBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.RootObjectFactory object");
    return 1;
}

void RootObjectFactoryBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       RootObjectFactoryBinding::gc },
        { "__tostring", RootObjectFactoryBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "mainThreadUpdate", RootObjectFactoryBinding::mainThreadUpdate },
        { "_DESTRUCTOR", RootObjectFactoryBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        RootObjectFactoryBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, RootObjectFactoryBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, RootObjectFactory_get_todoMutex);
    lua_setfield(L, -2, "todoMutex");
    lua_pushcfunction(L, RootObjectFactory_get_todoList);
    lua_setfield(L, -2, "todoList");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, RootObjectFactory_set_todoMutex);
    lua_setfield(L, -2, "todoMutex");
    lua_pushcfunction(L, RootObjectFactory_set_todoList);
    lua_setfield(L, -2, "todoList");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua