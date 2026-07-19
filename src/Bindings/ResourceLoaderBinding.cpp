#include "pch.h"
#include "kenshi\ResourceLoader.h"
#include "ResourceLoaderBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static ResourceLoader* getInstance(lua_State* L, int idx)
{
    return checkObject<ResourceLoader>(L, idx, ResourceLoaderBinding::getMetatableName());
}

// --- Getters for ResourceLoader ---
static int ResourceLoader_get_running(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    lua_pushboolean(L, instance->running ? 1 : 0);
    return 1;
}

static int ResourceLoader_get_sceneManager(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    lua_pushlightuserdata(L, (void*)instance->sceneManager);
    return 1;
}

static int ResourceLoader_get_loadingMeshQueueMutex(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    lua_pushlightuserdata(L, (void*)&instance->loadingMeshQueueMutex);
    return 1;
}

static int ResourceLoader_get_texturesLoadingMutex(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    lua_pushlightuserdata(L, (void*)&instance->texturesLoadingMutex);
    return 1;
}

static int ResourceLoader_get_texturesLoadedMutex(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    lua_pushlightuserdata(L, (void*)&instance->texturesLoadedMutex);
    return 1;
}

// --- Setters for ResourceLoader ---
static int ResourceLoader_set_running(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");
    instance->running = lua_toboolean(L, 2) != 0;
    return 0;
}

static int ResourceLoader_set_loadingMeshQueueMutex(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for loadingMeshQueueMutex");
}

static int ResourceLoader_set_texturesLoadingMutex(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for texturesLoadingMutex");
}

static int ResourceLoader_set_texturesLoadedMutex(lua_State* L)
{
    return luaL_error(L, "Read-only or unsupported setter type for texturesLoadedMutex");
}

int ResourceLoaderBinding::updateMT(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    instance->updateMT();
    return 0;
}

int ResourceLoaderBinding::updateBT(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    bool result = instance->updateBT();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResourceLoaderBinding::isLoading(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    bool result = instance->isLoading();
    lua_pushboolean(L, result ? 1 : 0);
    return 1;
}

int ResourceLoaderBinding::_CONSTRUCTOR(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    ResourceLoader* result = instance->_CONSTRUCTOR();
    lua_pushlightuserdata(L, (void*)result);
    return 1;
}

int ResourceLoaderBinding::_DESTRUCTOR(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    instance->_DESTRUCTOR();
    return 0;
}

int ResourceLoaderBinding::init(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    instance->init();
    return 0;
}

int ResourceLoaderBinding::threadProc(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    unsigned long result = instance->threadProc();
    lua_pushinteger(L, result);
    return 1;
}

int ResourceLoaderBinding::_NV_threadProc(lua_State* L)
{
    ResourceLoader* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "ResourceLoader is nil");

    unsigned long result = instance->_NV_threadProc();
    lua_pushinteger(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 97: boost::function<void __cdecl(...) - static method
  line 98: ResourceLoader* getInstance(...) - static method
  line 99: void destroy(...) - overloaded method
  line 100: void destroy(...) - overloaded method
  line 101: void destroy(...) - overloaded method
  line 102: void destroy(...) - overloaded method
  line 103: void destroy(...) - overloaded method
  line 104: Ogre::Entity* loadModelEntity(...) - unsupported arg type
  line 105: Ogre::Entity* loadModelEntityDetached(...) - unsupported arg type
  line 106: void loadTextureUnitArray(...) - unsupported arg type
  line 107: void loadTextureUnit(...) - unsupported arg type
  line 108: bool isTextureLoaded(...) - unsupported arg type
  line 109: Ogre::SceneNode* getSceneNode(...) - unsupported arg type
  line 110: void releaseSceneNode(...) - unsupported arg type
  line 111: void removeRequest(...) - unsupported arg type
  line 139: unsigned __int64 setupResourceMesh(...) - unsupported return type
  line 140: Ogre::Entity* createLoadRequestMesh(...) - unsupported arg type
  line 141: void operationCompleted(...) - unsupported arg type
  line 142: void _NV_operationCompleted(...) - unsupported arg type
  line 143: bool abortLoadRequest(...) - unsupported arg type
  line 161: void SetMeshData(...) - static method
*/

/*
Skipped properties needing manual binding:
  line 148: activeMeshLoaders (ogre_unordered_map<unsigned __int64, ResourceLoadRequestMesh*>::type) - unsupported type
  line 149: abortedMeshLoaders (ogre_unordered_map<unsigned __int64, ResourceLoadRequestMesh*>::type) - unsupported type
  line 150: loadedMeshesList (std::list<ResourceLoadRequestMesh*, Ogre::STLAllocator<ResourceLoadRequestMesh*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 151: loadingMeshQueue (std::list<ResourceLoadRequestMesh*, Ogre::STLAllocator<ResourceLoadRequestMesh*, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 153: activeTextureLoaders (boost::unordered::unordered_map<TextureLoadData*, Ogre::FastArray<ResourceLoadRequestTexture*>, boost::hash<TextureLoadData*>, std::equal_to<TextureLoadData*>, Ogre::STLAllocator<std::pair<TextureLoadData*const, Ogre::FastArray<ResourceLoadRequestTexture*> >, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 154: texturesToLoad (ogre_unordered_set<TextureLoadData*>::type) - unsupported type
  line 157: texturesLoading (Ogre::FastArray<TextureLoadData*>) - unsupported type
  line 158: texturesLoaded (Ogre::FastArray<TextureLoadData*>) - unsupported type
  line 159: manualTexturesLoaded (boost::unordered::unordered_map<Ogre::SharedPtr<Ogre::Texture>, float, boost::hash<Ogre::SharedPtr<Ogre::Texture> >, std::equal_to<Ogre::SharedPtr<Ogre::Texture> >, Ogre::STLAllocator<std::pair<Ogre::SharedPtr<Ogre::Texture> const, float>, Ogre::GeneralAllocPolicy > >) - unsupported type
  line 160: textureUnitsLoading (ogre_unordered_set<Ogre::TextureUnitState*>::type) - unsupported type
*/

int ResourceLoaderBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int ResourceLoaderBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.ResourceLoader object");
    return 1;
}

void ResourceLoaderBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       ResourceLoaderBinding::gc },
        { "__tostring", ResourceLoaderBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "updateMT", ResourceLoaderBinding::updateMT },
        { "updateBT", ResourceLoaderBinding::updateBT },
        { "isLoading", ResourceLoaderBinding::isLoading },
        { "_CONSTRUCTOR", ResourceLoaderBinding::_CONSTRUCTOR },
        { "_DESTRUCTOR", ResourceLoaderBinding::_DESTRUCTOR },
        { "init", ResourceLoaderBinding::init },
        { "threadProc", ResourceLoaderBinding::threadProc },
        { "_NV_threadProc", ResourceLoaderBinding::_NV_threadProc },
        { 0, 0 }
    };

    registerClass(
        L, 
        ResourceLoaderBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, ResourceLoaderBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    lua_pushcfunction(L, ResourceLoader_get_running);
    lua_setfield(L, -2, "running");
    lua_pushcfunction(L, ResourceLoader_get_sceneManager);
    lua_setfield(L, -2, "sceneManager");
    lua_pushcfunction(L, ResourceLoader_get_loadingMeshQueueMutex);
    lua_setfield(L, -2, "loadingMeshQueueMutex");
    lua_pushcfunction(L, ResourceLoader_get_texturesLoadingMutex);
    lua_setfield(L, -2, "texturesLoadingMutex");
    lua_pushcfunction(L, ResourceLoader_get_texturesLoadedMutex);
    lua_setfield(L, -2, "texturesLoadedMutex");
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    lua_pushcfunction(L, ResourceLoader_set_running);
    lua_setfield(L, -2, "running");
    lua_pushcfunction(L, ResourceLoader_set_loadingMeshQueueMutex);
    lua_setfield(L, -2, "loadingMeshQueueMutex");
    lua_pushcfunction(L, ResourceLoader_set_texturesLoadingMutex);
    lua_setfield(L, -2, "texturesLoadingMutex");
    lua_pushcfunction(L, ResourceLoader_set_texturesLoadedMutex);
    lua_setfield(L, -2, "texturesLoadedMutex");
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::ResourceBackgroundQueue::Listener
    // setMetatableParent(L, ResourceLoaderBinding::getMetatableName(), Ogre::ResourceBackgroundQueue::ListenerBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua
