#include "pch.h"
#include "kenshi\gui\TutorialGUI.h"
#include "TutorialItemBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/Gui/TutorialSubItemBinding.h"
#include "Bindings/Util/OgreFastArrayBinding.h"

namespace KenshiLua
{
typedef OgreFastArrayPtrBinding<TutorialSubItem*> TutorialSubItemFastArrayBinding;
typedef OgreFastArrayPrimitiveBinding<std::string> StringFastArrayBinding;
typedef OgreFastArrayPtrBinding<TutorialItem*> TutorialItemFastArrayBinding;

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

static int TutorialItem_get_subItems(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    return pushObject<TutorialSubItemFastArrayBinding::ArrayType>(L, &instance->subItems, "Ogre::FastArray<TutorialSubItem*>");
}

static int TutorialItem_get_requiredTutorialsStr(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    return pushObject<StringFastArrayBinding::ArrayType>(L, &instance->requiredTutorialsStr, "Ogre::FastArray<std::string>");
}

static int TutorialItem_get_requiredTutorials(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    return pushObject<TutorialItemFastArrayBinding::ArrayType>(L, &instance->requiredTutorials, "Ogre::FastArray<TutorialItem*>");
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

static int TutorialItem_set_subItems(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->subItems.clear();
        return 0;
    }
    auto* src = TutorialSubItemFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set subItems must be Ogre::FastArray<TutorialSubItem*>");
    instance->subItems = *src;
    return 0;
}

static int TutorialItem_set_requiredTutorialsStr(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->requiredTutorialsStr.clear();
        return 0;
    }
    auto* src = StringFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set requiredTutorialsStr must be Ogre::FastArray<std::string>");
    instance->requiredTutorialsStr = *src;
    return 0;
}

static int TutorialItem_set_requiredTutorials(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");
    if (lua_isnoneornil(L, 2))
    {
        instance->requiredTutorials.clear();
        return 0;
    }
    auto* src = TutorialItemFastArrayBinding::get(L, 2);
    if (!src) return luaL_error(L, "Argument 2 to set requiredTutorials must be Ogre::FastArray<TutorialItem*>");
    instance->requiredTutorials = *src;
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
    return pushObject<TutorialSubItem>(L, result, TutorialSubItemBinding::getMetatableName());
}

int TutorialItemBinding::getSubItemAt(lua_State* L)
{
    TutorialItem* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "TutorialItem is nil");

    int index = (int)luaL_checkinteger(L, 2);
    TutorialSubItem* result = instance->getSubItemAt(index);
    return pushObject<TutorialSubItem>(L, result, TutorialSubItemBinding::getMetatableName());
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
    registerGetter(L, "id", TutorialItem_get_id);
    registerGetter(L, "started", TutorialItem_get_started);
    registerGetter(L, "locked", TutorialItem_get_locked);
    registerGetter(L, "title", TutorialItem_get_title);
    registerGetter(L, "state", TutorialItem_get_state);
    registerGetter(L, "subItemIndex", TutorialItem_get_subItemIndex);
    registerGetter(L, "subItems", TutorialItem_get_subItems);
    registerGetter(L, "requiredTutorialsStr", TutorialItem_get_requiredTutorialsStr);
    registerGetter(L, "requiredTutorials", TutorialItem_get_requiredTutorials);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "id", TutorialItem_set_id);
    registerSetter(L, "started", TutorialItem_set_started);
    registerSetter(L, "locked", TutorialItem_set_locked);
    registerSetter(L, "title", TutorialItem_set_title);
    registerSetter(L, "state", TutorialItem_set_state);
    registerSetter(L, "subItemIndex", TutorialItem_set_subItemIndex);
    registerSetter(L, "subItems", TutorialItem_set_subItems);
    registerSetter(L, "requiredTutorialsStr", TutorialItem_set_requiredTutorialsStr);
    registerSetter(L, "requiredTutorials", TutorialItem_set_requiredTutorials);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    TutorialSubItemFastArrayBinding::registerBinding(L, "Ogre::FastArray<TutorialSubItem*>", TutorialSubItemBinding::getMetatableName());
    StringFastArrayBinding::registerBinding(L, "Ogre::FastArray<std::string>");
    TutorialItemFastArrayBinding::registerBinding(L, "Ogre::FastArray<TutorialItem*>", TutorialItemBinding::getMetatableName());

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, TutorialItemBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua