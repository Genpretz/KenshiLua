#include "pch.h"
#include "kenshi/HandleManager.h"
#include "HandleListBinding.h"
#include "HandleListBaseBinding.h"
#include "Bindings/Kenshi/RootObjectBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(HandleList, containerHandle) == 0x18, "HandleList::containerHandle offset mismatch");
static_assert(offsetof(HandleList, handleShift) == 0x38, "HandleList::handleShift offset mismatch");

typedef StdMapBinding<unsigned __int64, unsigned int> HandleShiftMapBinding;

static HandleList* getInstance(lua_State* L, int idx)
{
    return checkObject<HandleList>(L, idx, HandleListBinding::getMetatableName());
}

static int HandleList_get_containerHandle(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    return HandBinding::push(L, instance->containerHandle);
}

static int HandleList_set_containerHandle(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 to set containerHandle must be hand");
    instance->containerHandle = *h;
    return 0;
}

static int HandleList_get_handleShift(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    return pushObject<HandleShiftMapBinding::MapType>(L, &instance->handleShift, "std::map<unsigned __int64, unsigned int>");
}

static int HandleList_set_handleShift(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    auto* val = HandleShiftMapBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set handleShift must be std::map<unsigned __int64, unsigned int>");
    instance->handleShift = *val;
    return 0;
}

int HandleListBinding::add(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand res = instance->add(o);
    return HandBinding::push(L, res);
}

int HandleListBinding::_NV_add(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand res = instance->_NV_add(o);
    return HandBinding::push(L, res);
}

int HandleListBinding::get(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObjectBase* res = instance->get(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int HandleListBinding::_NV_get(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    RootObjectBase* res = instance->_NV_get(*h);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<RootObjectBase>(L, res, RootObjectBaseBinding::getMetatableName());
}

int HandleListBinding::addExisting(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->addExisting(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBinding::_NV_addExisting(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->_NV_addExisting(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBinding::addExistingAndForceContainer(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->addExistingAndForceContainer(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBinding::_NV_addExistingAndForceContainer(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    RootObjectBase* o = checkObject<RootObjectBase>(L, 2, RootObjectBaseBinding::getMetatableName());
    hand* h = checkObject<hand>(L, 3, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 2 must be hand");
    hand res = instance->_NV_addExistingAndForceContainer(o, *h);
    return HandBinding::push(L, res);
}

int HandleListBinding::destroy(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->destroy(*h);
    return 0;
}

int HandleListBinding::_NV_destroy(lua_State* L)
{
    HandleList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "HandleList is nil");
    hand* h = checkObject<hand>(L, 2, HandBinding::getMetatableName());
    if (!h) return luaL_error(L, "Argument 1 must be hand");
    instance->_NV_destroy(*h);
    return 0;
}

int HandleListBinding::gc(lua_State* L)
{
    return 0;
}

int HandleListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.HandleList object");
    return 1;
}

void HandleListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       HandleListBinding::gc },
        { "__tostring", HandleListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "add", HandleListBinding::add },
        { "_NV_add", HandleListBinding::_NV_add },
        { "get", HandleListBinding::get },
        { "_NV_get", HandleListBinding::_NV_get },
        { "addExisting", HandleListBinding::addExisting },
        { "_NV_addExisting", HandleListBinding::_NV_addExisting },
        { "addExistingAndForceContainer", HandleListBinding::addExistingAndForceContainer },
        { "_NV_addExistingAndForceContainer", HandleListBinding::_NV_addExistingAndForceContainer },
        { "destroy", HandleListBinding::destroy },
        { "_NV_destroy", HandleListBinding::_NV_destroy },
        { 0, 0 }
    };

    registerClass(
        L,
        HandleListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, HandleListBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "containerHandle", HandleList_get_containerHandle);
    registerGetter(L, "handleShift", HandleList_get_handleShift);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "containerHandle", HandleList_set_containerHandle);
    registerSetter(L, "handleShift", HandleList_set_handleShift);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

    HandleShiftMapBinding::registerBinding(L, "std::map<unsigned __int64, unsigned int>", nullptr, nullptr);
}

} // namespace KenshiLua

