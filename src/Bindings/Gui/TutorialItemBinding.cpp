#include "pch.h"
#include <kenshi/gui/TutorialGUI.h>
#include "TutorialItemBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static TutorialItem* getInstance(lua_State* L, int idx)
{
    return checkObject<TutorialItem>(L, idx, TutorialItemBinding::getMetatableName());
}

// --- Getters for TutorialItem ---
static int TutorialItem_get_id(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushinteger(L, instance->id);
    return 1;
}

static int TutorialItem_get_started(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushboolean(L, instance->started ? 1 : 0);
    return 1;
}

static int TutorialItem_get_locked(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushboolean(L, instance->locked ? 1 : 0);
    return 1;
}

static int TutorialItem_get_title(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushstring(L, instance->title.c_str());
    return 1;
}

static int TutorialItem_get_state(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushinteger(L, (lua_Integer)instance->state);
    return 1;
}

static int TutorialItem_get_subItemIndex(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    lua_pushinteger(L, instance->subItemIndex);
    return 1;
}

// --- Setters for TutorialItem ---
static int TutorialItem_set_id(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->id = (unsigned int)luaL_checkinteger(L, 2);
    return 0;
}

static int TutorialItem_set_started(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->started = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TutorialItem_set_locked(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->locked = lua_toboolean(L, 2) != 0;
    return 0;
}

static int TutorialItem_set_title(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->title = luaL_checkstring(L, 2);
    return 0;
}

static int TutorialItem_set_state(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->state = (TutorialItem::State)luaL_checkinteger(L, 2);
    return 0;
}

static int TutorialItem_set_subItemIndex(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    instance->subItemIndex = (unsigned char)luaL_checkinteger(L, 2);
    return 0;
}

int TutorialItemBinding::_CONSTRUCTOR(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    TutorialItem* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TutorialItemBinding::_DESTRUCTOR(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int TutorialItemBinding::getId(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    unsigned int result = instance->getId();
    lua_pushinteger(L, result);
    return 1;
}

int TutorialItemBinding::isLastSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->isLastSubItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::isSkippable(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->isSkippable();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::isActive(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->isActive();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::hasEnded(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->hasEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::getCurrentSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    TutorialSubItem* result = instance->getCurrentSubItem();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TutorialItemBinding::getSubItemAt(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    int index = (int)luaL_checkinteger(L, 2);
    TutorialSubItem* result = instance->getSubItemAt(index);
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int TutorialItemBinding::getCurrentSubItemIndex(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    int result = instance->getCurrentSubItemIndex();
    lua_pushinteger(L, result);
    return 1;
}

int TutorialItemBinding::getNumSubItems(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    int result = instance->getNumSubItems();
    lua_pushinteger(L, result);
    return 1;
}

int TutorialItemBinding::hasNextSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->hasNextSubItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::hasPrevSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->hasPrevSubItem();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::nextSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->nextSubItem();
    return 0;
}

int TutorialItemBinding::prevSubItem(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->prevSubItem();
    return 0;
}

int TutorialItemBinding::getStarted(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->getStarted();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::getEnded(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->getEnded();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::reset(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->reset();
    return 0;
}

int TutorialItemBinding::_NV_reset(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->_NV_reset();
    return 0;
}

int TutorialItemBinding::conditionsMet(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->conditionsMet();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::start(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->start();
    return 0;
}

int TutorialItemBinding::_NV_start(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->_NV_start();
    return 0;
}

int TutorialItemBinding::run(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->run();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::_NV_run(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    bool result = instance->_NV_run();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int TutorialItemBinding::end(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->end();
    return 0;
}

int TutorialItemBinding::_NV_end(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    instance->_NV_end();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 49: const std::string& getTitle(...) - reference return type
*/

/*
Skipped properties needing manual binding:
  line 79: subItems (Ogre::FastArray<TutorialSubItem*>) - unsupported type
  line 80: requiredTutorialsStr (Ogre::FastArray<std::string >) - unsupported type
  line 81: requiredTutorials (Ogre::FastArray<TutorialItem*>) - unsupported type
*/

int TutorialItemBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TutorialItemBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.TutorialItem object");
    return 1;
}

void TutorialItemBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TutorialItemBinding::gc },
        { "__tostring", TutorialItemBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "_CONSTRUCTOR", TutorialItemBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", TutorialItemBinding::_DESTRUCTOR },
        { "getId", TutorialItemBinding::getId },
        { "isLastSubItem", TutorialItemBinding::isLastSubItem },
        { "isSkippable", TutorialItemBinding::isSkippable },
        { "isActive", TutorialItemBinding::isActive },
        { "hasEnded", TutorialItemBinding::hasEnded },
        { "getCurrentSubItem", TutorialItemBinding::getCurrentSubItem },
        { "getSubItemAt", TutorialItemBinding::getSubItemAt },
        { "getCurrentSubItemIndex", TutorialItemBinding::getCurrentSubItemIndex },
        { "getNumSubItems", TutorialItemBinding::getNumSubItems },
        { "hasNextSubItem", TutorialItemBinding::hasNextSubItem },
        { "hasPrevSubItem", TutorialItemBinding::hasPrevSubItem },
        { "nextSubItem", TutorialItemBinding::nextSubItem },
        { "prevSubItem", TutorialItemBinding::prevSubItem },
        { "getStarted", TutorialItemBinding::getStarted },
        { "getEnded", TutorialItemBinding::getEnded },
        { "reset", TutorialItemBinding::reset },
        { "_NV_reset", TutorialItemBinding::_NV_reset },
        { "conditionsMet", TutorialItemBinding::conditionsMet },
        { "start", TutorialItemBinding::start },
        { "_NV_start", TutorialItemBinding::_NV_start },
        { "run", TutorialItemBinding::run },
        { "_NV_run", TutorialItemBinding::_NV_run },
        { "end", TutorialItemBinding::end },
        { "_NV_end", TutorialItemBinding::_NV_end },
        { 0, 0 }
    };

    registerClass(
        L, 
        TutorialItemBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TutorialItemBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, TutorialItem_get_id);
    lua_setfield(L, -2, "id");
    lua_pushcfunction(L, TutorialItem_get_started);
    lua_setfield(L, -2, "started");
    lua_pushcfunction(L, TutorialItem_get_locked);
    lua_setfield(L, -2, "locked");
    lua_pushcfunction(L, TutorialItem_get_title);
    lua_setfield(L, -2, "title");
    lua_pushcfunction(L, TutorialItem_get_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, TutorialItem_get_subItemIndex);
    lua_setfield(L, -2, "subItemIndex");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, TutorialItem_set_id);
    lua_setfield(L, -2, "id");
    lua_pushcfunction(L, TutorialItem_set_started);
    lua_setfield(L, -2, "started");
    lua_pushcfunction(L, TutorialItem_set_locked);
    lua_setfield(L, -2, "locked");
    lua_pushcfunction(L, TutorialItem_set_title);
    lua_setfield(L, -2, "title");
    lua_pushcfunction(L, TutorialItem_set_state);
    lua_setfield(L, -2, "state");
    lua_pushcfunction(L, TutorialItem_set_subItemIndex);
    lua_setfield(L, -2, "subItemIndex");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // // // // // // // // // setMetatableParent(L, TutorialItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua