#include "pch.h"
#include "kenshi/Animation/AnimationClass.h"
#include "AnimsListsManagerBinding.h"
#include "AnimsListsManager_AnimListBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static_assert(offsetof(AnimsListsManager, characterAnimations) == 0x0, "AnimsListsManager::characterAnimations offset mismatch");

static AnimsListsManager* getInstance(lua_State* L, int idx)
{
    return checkObject<AnimsListsManager>(L, idx, AnimsListsManagerBinding::getMetatableName());
}

static int AnimsListsManager_get_characterAnimations(lua_State* L)
{
    AnimsListsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimsListsManager is nil");
    return pushObject<AnimsListsManager::AnimList>(L, &instance->characterAnimations, AnimsListsManager_AnimListBinding::getMetatableName());
}

int AnimsListsManagerBinding::getSingleton(lua_State* L)
{
    AnimsListsManager* s = AnimsListsManager::getSingleton();
    if (!s) { lua_pushnil(L); return 1; }
    return pushObject<AnimsListsManager>(L, s, AnimsListsManagerBinding::getMetatableName());
}

int AnimsListsManagerBinding::getAnimalList(lua_State* L)
{
    AnimsListsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimsListsManager is nil");
    GameData* race = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* animData = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    AnimsListsManager::AnimList* res = instance->getAnimalList(race, animData);
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<AnimsListsManager::AnimList>(L, res, AnimsListsManager_AnimListBinding::getMetatableName());
}

int AnimsListsManagerBinding::getCharacterList(lua_State* L)
{
    AnimsListsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimsListsManager is nil");
    AnimsListsManager::AnimList* res = instance->getCharacterList();
    if (!res) { lua_pushnil(L); return 1; }
    return pushObject<AnimsListsManager::AnimList>(L, res, AnimsListsManager_AnimListBinding::getMetatableName());
}

int AnimsListsManagerBinding::setupCharacterList(lua_State* L)
{
    AnimsListsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimsListsManager is nil");
    instance->setupCharacterList();
    return 0;
}

int AnimsListsManagerBinding::setupAnimalList(lua_State* L)
{
    AnimsListsManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "AnimsListsManager is nil");
    GameData* animalRace = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    GameData* getAnimsFrom = checkObject<GameData>(L, 3, GameDataBinding::getMetatableName());
    instance->setupAnimalList(animalRace, getAnimsFrom);
    return 0;
}

int AnimsListsManagerBinding::gc(lua_State* L)
{
    return 0;
}

int AnimsListsManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.AnimsListsManager object");
    return 1;
}

void AnimsListsManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       AnimsListsManagerBinding::gc },
        { "__tostring", AnimsListsManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getAnimalList", AnimsListsManagerBinding::getAnimalList },
        { "getCharacterList", AnimsListsManagerBinding::getCharacterList },
        { "setupCharacterList", AnimsListsManagerBinding::setupCharacterList },
        { "setupAnimalList", AnimsListsManagerBinding::setupAnimalList },
        { 0, 0 }
    };

    registerClass(
        L,
        AnimsListsManagerBinding::getMetatableName(),
        meta,
        methods,
        genericPropertyIndex,
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, AnimsListsManagerBinding::getMetatableName());
    lua_newtable(L);
    registerGetter(L, "characterAnimations", AnimsListsManager_get_characterAnimations);
    lua_setfield(L, -2, "__getters");

    lua_newtable(L);
    lua_setfield(L, -2, "__setters");

    lua_pop(L, 1);

    pushGlobalTable(L, "AnimsListsManager");
    registerStaticMethod(L, "getSingleton", AnimsListsManagerBinding::getSingleton);
    lua_setglobal(L, "AnimsListsManager");
}

} // namespace KenshiLua

