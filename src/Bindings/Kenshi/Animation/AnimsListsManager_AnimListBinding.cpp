#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimsListsManager_AnimListBinding.h"
#include "AnimationDataBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

typedef AnimsListsManager::AnimList AnimList;
typedef boost::unordered::unordered_map<std::string, AnimationData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy> > AnimStringMap;
typedef BoostUnorderedMapBinding<std::string, AnimationData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy> > AnimStringMapBinding;

static_assert(offsetof(AnimList, movementAnimsBase) == 0x0, "AnimList::movementAnimsBase offset mismatch");
static_assert(offsetof(AnimList, movementAnimsUpper) == 0x18, "AnimList::movementAnimsUpper offset mismatch");
static_assert(offsetof(AnimList, idleAnims) == 0x30, "AnimList::idleAnims offset mismatch");
static_assert(offsetof(AnimList, strafeAnims) == 0x48, "AnimList::strafeAnims offset mismatch");
static_assert(offsetof(AnimList, attacks) == 0x60, "AnimList::attacks offset mismatch");
static_assert(offsetof(AnimList, actionAnims) == 0x78, "AnimList::actionAnims offset mismatch");
static_assert(offsetof(AnimList, allAnims) == 0xB8, "AnimList::allAnims offset mismatch");
static_assert(offsetof(AnimList, turningAnim) == 0xF8, "AnimList::turningAnim offset mismatch");

static AnimList* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimList>(L, idx, AnimsListsManager_AnimListBinding::getMetatableName());
}

static int AnimList_get_movementAnimsBase(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->movementAnimsBase, "lektor<AnimationData*>");
}

static int AnimList_set_movementAnimsBase(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'movementAnimsBase' must be lektor<AnimationData*>");
    instance->movementAnimsBase = *val;
    return 0;
}

static int AnimList_get_movementAnimsUpper(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->movementAnimsUpper, "lektor<AnimationData*>");
}

static int AnimList_set_movementAnimsUpper(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'movementAnimsUpper' must be lektor<AnimationData*>");
    instance->movementAnimsUpper = *val;
    return 0;
}

static int AnimList_get_idleAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->idleAnims, "lektor<AnimationData*>");
}

static int AnimList_set_idleAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'idleAnims' must be lektor<AnimationData*>");
    instance->idleAnims = *val;
    return 0;
}

static int AnimList_get_strafeAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->strafeAnims, "lektor<AnimationData*>");
}

static int AnimList_set_strafeAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'strafeAnims' must be lektor<AnimationData*>");
    instance->strafeAnims = *val;
    return 0;
}

static int AnimList_get_attacks(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return pushObject<lektor<AnimationData*>>(L, &instance->attacks, "lektor<AnimationData*>");
}

static int AnimList_set_attacks(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = LektorPtrBinding<AnimationData*>::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'attacks' must be lektor<AnimationData*>");
    instance->attacks = *val;
    return 0;
}

static int AnimList_get_actionAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return AnimStringMapBinding::push(L, &instance->actionAnims);
}

static int AnimList_set_actionAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = AnimStringMapBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'actionAnims' must be boost_unordered_map<std::string, AnimationData*>");
    instance->actionAnims = *val;
    return 0;
}

static int AnimList_get_allAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    return AnimStringMapBinding::push(L, &instance->allAnims);
}

static int AnimList_set_allAnims(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    auto* val = AnimStringMapBinding::getInstance(L, 2);
    if (!val) return luaL_error(L, "Argument 2 to set 'allAnims' must be boost_unordered_map<std::string, AnimationData*>");
    instance->allAnims = *val;
    return 0;
}

static int AnimList_get_turningAnim(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    if (!instance->turningAnim) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, instance->turningAnim, AnimationDataBinding::getMetatableName());
}

static int AnimList_set_turningAnim(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    instance->turningAnim = lua_isnoneornil(L, 2) ? nullptr : checkObject<AnimationData>(L, 2, AnimationDataBinding::getMetatableName());
    return 0;
}

int AnimsListsManager_AnimListBinding::getStumbles(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    GameData* bp = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    lektor<AnimationData*>* res = instance->getStumbles(bp);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<lektor<AnimationData*>>(L, res, "lektor<AnimationData*>");
}

int AnimsListsManager_AnimListBinding::getStrafe(lua_State* L)
{
    AnimList* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimList is nil");
    AnimationData* res = instance->getStrafe();
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<AnimationData>(L, res, AnimationDataBinding::getMetatableName());
}

int AnimsListsManager_AnimListBinding::gc(lua_State* L)
{
    return 0;
}

int AnimsListsManager_AnimListBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimsListsManager.AnimList object");
    return 1;
}

void AnimsListsManager_AnimListBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimsListsManager_AnimListBinding::gc },
        { "__tostring", AnimsListsManager_AnimListBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getStumbles", AnimsListsManager_AnimListBinding::getStumbles },
        { "getStrafe", AnimsListsManager_AnimListBinding::getStrafe },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimsListsManager_AnimListBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimsListsManager_AnimListBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "movementAnimsBase", AnimList_get_movementAnimsBase);
    registerGetter(L, "movementAnimsUpper", AnimList_get_movementAnimsUpper);
    registerGetter(L, "idleAnims", AnimList_get_idleAnims);
    registerGetter(L, "strafeAnims", AnimList_get_strafeAnims);
    registerGetter(L, "attacks", AnimList_get_attacks);
    registerGetter(L, "actionAnims", AnimList_get_actionAnims);
    registerGetter(L, "allAnims", AnimList_get_allAnims);
    registerGetter(L, "turningAnim", AnimList_get_turningAnim);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    registerSetter(L, "movementAnimsBase", AnimList_set_movementAnimsBase);
    registerSetter(L, "movementAnimsUpper", AnimList_set_movementAnimsUpper);
    registerSetter(L, "idleAnims", AnimList_set_idleAnims);
    registerSetter(L, "strafeAnims", AnimList_set_strafeAnims);
    registerSetter(L, "attacks", AnimList_set_attacks);
    registerSetter(L, "actionAnims", AnimList_set_actionAnims);
    registerSetter(L, "allAnims", AnimList_set_allAnims);
    registerSetter(L, "turningAnim", AnimList_set_turningAnim);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

    AnimStringMapBinding::registerBinding(L, "boost_unordered_map<std::string, AnimationData*>", nullptr, AnimationDataBinding::getMetatableName());
}

} // namespace KenshiLua

