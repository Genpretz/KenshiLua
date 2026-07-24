#include "pch.h"
#include "kenshi\gui\PortraitManager.h"
#include "PortraitManagerBinding.h"
#include "Lua/BindingHelpers.h"
#include "Bindings/ActivePlatoonBinding.h"
#include "Bindings/CharacterBinding.h"
#include "Bindings/Gui/PortraitDataBinding.h"
#include "Bindings/Util/iVector2Binding.h"

namespace KenshiLua
{

static PortraitManager* getInstance(lua_State* L, int idx)
{
    return checkObject<PortraitManager>(L, idx, PortraitManagerBinding::getMetatableName());
}

// --- Getters for PortraitManager ---
static int PortraitManager_get_textureSize(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    return pushObject<iVector2>(L, &instance->textureSize, iVector2Binding::getMetatableName());
}

static int PortraitManager_get_textureName(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    lua_pushstring(L, instance->textureName.c_str());
    return 1;
}

static int PortraitManager_get_texturePortraitSize(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    return pushObject<iVector2>(L, &instance->texturePortraitSize, iVector2Binding::getMetatableName());
}

static int PortraitManager_get_maxIndex(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    lua_pushinteger(L, instance->maxIndex);
    return 1;
}

static int PortraitManager_get_imagesIndices(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    lua_pushlightuserdata(L, (void*)instance->imagesIndices);
    return 1;
}

static int PortraitManager_get_disableUpdate(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    lua_pushboolean(L, instance->disableUpdate ? 1 : 0);
    return 1;
}

// --- Setters for PortraitManager ---
static int PortraitManager_set_textureSize(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    instance->textureSize = *checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    return 0;
}

static int PortraitManager_set_textureName(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    instance->textureName = luaL_checkstring(L, 2);
    return 0;
}

static int PortraitManager_set_texturePortraitSize(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    instance->texturePortraitSize = *checkObject<iVector2>(L, 2, iVector2Binding::getMetatableName());
    return 0;
}

static int PortraitManager_set_maxIndex(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    instance->maxIndex = (unsigned short)luaL_checkinteger(L, 2);
    return 0;
}

static int PortraitManager_set_disableUpdate(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");
    instance->disableUpdate = lua_toboolean(L, 2) != 0;
    return 0;
}

int PortraitManagerBinding::init(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->init();
    return 0;
}

int PortraitManagerBinding::destroy(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->destroy();
    return 0;
}

int PortraitManagerBinding::setUpdateEnabled(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    bool enabled = lua_toboolean(L, 2) != 0;
    instance->setUpdateEnabled(enabled);
    return 0;
}

int PortraitManagerBinding::reloadPortraits(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->reloadPortraits();
    return 0;
}

int PortraitManagerBinding::reloadTexture(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->reloadTexture();
    return 0;
}

int PortraitManagerBinding::saveTexture(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->saveTexture();
    return 0;
}

int PortraitManagerBinding::clearPortraits(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    bool loadTexture = lua_toboolean(L, 2) != 0;
    instance->clearPortraits(loadTexture);
    return 0;
}

int PortraitManagerBinding::getCharacterFlashing(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->getCharacterFlashing(character);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitManagerBinding::getCharacterInCombat(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->getCharacterInCombat(character);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitManagerBinding::getCharacterDown(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    Character* character = checkObject<Character>(L, 2, CharacterBinding::getMetatableName());
    bool result = instance->getCharacterDown(character);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitManagerBinding::getSquadFlashing(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    ActivePlatoon* platoon = checkObject<ActivePlatoon>(L, 2, ActivePlatoonBinding::getMetatableName());
    bool result = instance->getSquadFlashing(platoon);
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int PortraitManagerBinding::_CONSTRUCTOR(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    PortraitManager* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int PortraitManagerBinding::_DESTRUCTOR(lua_State* L)
{
    PortraitManager* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "PortraitManager is nil");

    instance->_DESTRUCTOR();
    return 0;
}

/*
Skipped methods needing manual binding:
  line 39: PortraitManager* getInstance(...) - static method
  line 46: PortraitData* getPortrait(...) - non-string reference arg
  line 47: void updatePortrait(...) - non-string reference arg
  line 48: bool updatePortraitImage(...) - non-string reference arg
  line 50: void setImageWidget(...) - non-string reference arg
  line 60: bool createPortraitImage(...) - unsupported arg type
  line 61: void getNextIndices(...) - non-string reference arg
  line 62: void setImageWidgetNPC(...) - unsupported arg type
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - PortraitManager_get_imagesIndices: bool* (unbound pointer)
  - PortraitManagerBinding::_CONSTRUCTOR: PortraitManager* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 67: texture (Ogre::SharedPtr<Ogre::Texture>) - unsupported type
  line 68: images (std::vector<std::pair<bool, PortraitImage*>, Ogre::STLAllocator<std::pair<bool, PortraitImage*>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 69: characterPortraits (std::map<hand, std::pair<PortraitData*, PortraitImage*>, std::less<hand>, Ogre::STLAllocator<std::pair<hand const, std::pair<PortraitData*, PortraitImage*> >, Ogre::GeneralAllocPolicy > >) - unsupported type
*/

int PortraitManagerBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int PortraitManagerBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.PortraitManager object");
    return 1;
}

void PortraitManagerBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       PortraitManagerBinding::gc },
        { "__tostring", PortraitManagerBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "init", PortraitManagerBinding::init },
        { "destroy", PortraitManagerBinding::destroy },
        { "setUpdateEnabled", PortraitManagerBinding::setUpdateEnabled },
        { "reloadPortraits", PortraitManagerBinding::reloadPortraits },
        { "reloadTexture", PortraitManagerBinding::reloadTexture },
        { "saveTexture", PortraitManagerBinding::saveTexture },
        { "clearPortraits", PortraitManagerBinding::clearPortraits },
        { "getCharacterFlashing", PortraitManagerBinding::getCharacterFlashing },
        { "getCharacterInCombat", PortraitManagerBinding::getCharacterInCombat },
        { "getCharacterDown", PortraitManagerBinding::getCharacterDown },
        { "getSquadFlashing", PortraitManagerBinding::getSquadFlashing },
        { "_CONSTRUCTOR", PortraitManagerBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", PortraitManagerBinding::_DESTRUCTOR },
        { 0, 0 }
    };

    registerClass(
        L, 
        PortraitManagerBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, PortraitManagerBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "textureSize", PortraitManager_get_textureSize);
    registerGetter(L, "textureName", PortraitManager_get_textureName);
    registerGetter(L, "texturePortraitSize", PortraitManager_get_texturePortraitSize);
    registerGetter(L, "maxIndex", PortraitManager_get_maxIndex);
    registerGetter(L, "imagesIndices", PortraitManager_get_imagesIndices);
    registerGetter(L, "disableUpdate", PortraitManager_get_disableUpdate);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "textureSize", PortraitManager_set_textureSize);
    registerSetter(L, "textureName", PortraitManager_set_textureName);
    registerSetter(L, "texturePortraitSize", PortraitManager_set_texturePortraitSize);
    registerSetter(L, "maxIndex", PortraitManager_set_maxIndex);
    registerSetter(L, "disableUpdate", PortraitManager_set_disableUpdate);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::GeneralAllocatedObject
    // setMetatableParent(L, PortraitManagerBinding::getMetatableName(), Ogre::GeneralAllocatedObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua