#include "pch.h"
#include "kenshi\terrain.h"
#include "TerrainBinding.h"
#include "Lua/BindingHelpers.h"

namespace KenshiLua
{

static Terrain* getInstance(lua_State* L, int idx)
{
    return checkObject<Terrain>(L, idx, TerrainBinding::getMetatableName());
}

// --- Getters for Terrain ---
static int Terrain_get_mCamera(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, (void*)instance->mCamera);
    return 1;
}

static int Terrain_get_mCameraPosition(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    pushVector3(L, instance->mCameraPosition);
    return 1;
}

static int Terrain_get_mStream(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, (void*)instance->mStream);
    return 1;
}

static int Terrain_get_mTerrain(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, (void*)instance->mTerrain);
    return 1;
}

static int Terrain_get_mSize(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mSize);
    return 1;
}

static int Terrain_get_mHeight(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mHeight);
    return 1;
}

static int Terrain_get_mHeightScale(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mHeightScale);
    return 1;
}

static int Terrain_get_mOffset(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mOffset);
    return 1;
}

static int Terrain_get_mSizeScale(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mSizeScale);
    return 1;
}

static int Terrain_get_mBuildCounter(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mBuildCounter);
    return 1;
}

static int Terrain_get_mNeedsBuilding(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushboolean(L, instance->mNeedsBuilding ? 1 : 0);
    return 1;
}

static int Terrain_get_mPatchesToBuild(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mPatchesToBuild);
    return 1;
}

static int Terrain_get_mOnscreenLimit(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mOnscreenLimit);
    return 1;
}

static int Terrain_get_mOffscreenLimit(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mOffscreenLimit);
    return 1;
}

static int Terrain_get_mDrawableCount(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mDrawableCount);
    return 1;
}

static int Terrain_get_mMaterialDistance(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushnumber(L, instance->mMaterialDistance);
    return 1;
}

static int Terrain_get_mHeightCacheSize(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mHeightCacheSize);
    return 1;
}

static int Terrain_get_mHeightCacheBox(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, &instance->mHeightCacheBox);
    return 1;
}

static int Terrain_get_mCachePositionX(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mCachePositionX);
    return 1;
}

static int Terrain_get_mCachePositionY(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushinteger(L, instance->mCachePositionY);
    return 1;
}

static int Terrain_get_mHeightCache(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, (void*)instance->mHeightCache);
    return 1;
}

static int Terrain_get_mBloodCamera(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    lua_pushlightuserdata(L, (void*)instance->mBloodCamera);
    return 1;
}

// --- Setters for Terrain ---
static int Terrain_set_mCameraPosition(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    readVector3(L, 2, instance->mCameraPosition);
    return 0;
}

static int Terrain_set_mSize(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mSize = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mHeight(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mHeight = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mHeightScale(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mHeightScale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mOffset(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mOffset = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mSizeScale(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mSizeScale = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mBuildCounter(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mBuildCounter = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mNeedsBuilding(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mNeedsBuilding = lua_toboolean(L, 2) != 0;
    return 0;
}

static int Terrain_set_mPatchesToBuild(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mPatchesToBuild = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mOnscreenLimit(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mOnscreenLimit = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mOffscreenLimit(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mOffscreenLimit = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mDrawableCount(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mDrawableCount = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mMaterialDistance(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mMaterialDistance = (float)luaL_checknumber(L, 2);
    return 0;
}

static int Terrain_set_mHeightCacheSize(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mHeightCacheSize = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mHeightCacheBox(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    Terrain::Box* val = (Terrain::Box*)lua_touserdata(L, 2);
    if (val) instance->mHeightCacheBox = *val;
    return 0;
}

static int Terrain_set_mCachePositionX(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mCachePositionX = (int)luaL_checkinteger(L, 2);
    return 0;
}

static int Terrain_set_mCachePositionY(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");
    instance->mCachePositionY = (int)luaL_checkinteger(L, 2);
    return 0;
}

int TerrainBinding::getBoundingRadius(lua_State* L)
{
    Terrain* instance = getInstance(L, 1);
    if (!instance) return luaL_error(L, "Terrain is nil");

    float result = instance->getBoundingRadius();
    lua_pushnumber(L, result);
    return 1;
}

/*
Skipped methods needing manual binding:
  line 21: const std::string& getMovableType(...) - reference return type
  line 22: const Ogre::AxisAlignedBox& getBoundingBox(...) - reference return type
  line 24: void _updateRenderQueue(...) - unsupported arg type
  line 25: void visitRenderables(...) - unsupported arg type
  line 26: void _notifyCurrentCamera(...) - unsupported arg type
  line 27: bool frameStarted(...) - unsupported arg type
  line 99: boost::function<Ogre::SharedPtr<Ogre::Material> __cdecl(...) - overloaded method
  line 100: boost::function<void __cdecl(...) - overloaded method
*/

/*
LIGHTUSERDATA DEPENDENCIES:
  - Terrain_get_mCamera: const Ogre::Camera* (unbound pointer)
  - Terrain_get_mStream: TiffStream* (unbound pointer)
  - Terrain_get_mTerrain: Landscape* (unbound pointer)
  - Terrain_get_mHeightCache: float* (unbound pointer)
  - Terrain_get_mBloodCamera: TerrainCamera* (unbound pointer)
*/

/*
Skipped properties needing manual binding:
  line 83: mBounds (Ogre::AxisAlignedBox) - unsupported type
  line 98: mDefaultMaterial (Ogre::SharedPtr<Ogre::Material>) - unsupported type
  line 129: mDecalQueue (std::vector<Terrain::BloodQueue>) - unsupported type
  line 130: mDecals (std::vector<TerrainDecal*>) - unsupported type
  line 131: mBloodMaterial (Ogre::SharedPtr<Ogre::Material>) - unsupported type
*/

int TerrainBinding::gc(lua_State* L)
{
    // Implementation depends on ownership model
    return 0;
}

int TerrainBinding::tostring(lua_State* L)
{
    lua_pushstring(L, "KenshiLua.Terrain object");
    return 1;
}

void TerrainBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       TerrainBinding::gc },
        { "__tostring", TerrainBinding::tostring },
        { 0, 0 }
    };

    static const luaL_Reg methods[] = {
        { "getBoundingRadius", TerrainBinding::getBoundingRadius },
        { 0, 0 }
    };

    registerClass(
        L, 
        TerrainBinding::getMetatableName(), 
        meta, 
        methods, 
        genericPropertyIndex, 
        genericPropertyNewIndex
    );

    luaL_getmetatable(L, TerrainBinding::getMetatableName());
    lua_newtable(L); // Create __getters table
    registerGetter(L, "mCamera", Terrain_get_mCamera);
    registerGetter(L, "mCameraPosition", Terrain_get_mCameraPosition);
    registerGetter(L, "mStream", Terrain_get_mStream);
    registerGetter(L, "mTerrain", Terrain_get_mTerrain);
    registerGetter(L, "mSize", Terrain_get_mSize);
    registerGetter(L, "mHeight", Terrain_get_mHeight);
    registerGetter(L, "mHeightScale", Terrain_get_mHeightScale);
    registerGetter(L, "mOffset", Terrain_get_mOffset);
    registerGetter(L, "mSizeScale", Terrain_get_mSizeScale);
    registerGetter(L, "mBuildCounter", Terrain_get_mBuildCounter);
    registerGetter(L, "mNeedsBuilding", Terrain_get_mNeedsBuilding);
    registerGetter(L, "mPatchesToBuild", Terrain_get_mPatchesToBuild);
    registerGetter(L, "mOnscreenLimit", Terrain_get_mOnscreenLimit);
    registerGetter(L, "mOffscreenLimit", Terrain_get_mOffscreenLimit);
    registerGetter(L, "mDrawableCount", Terrain_get_mDrawableCount);
    registerGetter(L, "mMaterialDistance", Terrain_get_mMaterialDistance);
    registerGetter(L, "mHeightCacheSize", Terrain_get_mHeightCacheSize);
    registerGetter(L, "mHeightCacheBox", Terrain_get_mHeightCacheBox);
    registerGetter(L, "mCachePositionX", Terrain_get_mCachePositionX);
    registerGetter(L, "mCachePositionY", Terrain_get_mCachePositionY);
    registerGetter(L, "mHeightCache", Terrain_get_mHeightCache);
    registerGetter(L, "mBloodCamera", Terrain_get_mBloodCamera);
    lua_setfield(L, -2, "__getters"); // Bind to metatable

    lua_newtable(L); // Create __setters table
    registerSetter(L, "mCameraPosition", Terrain_set_mCameraPosition);
    registerSetter(L, "mSize", Terrain_set_mSize);
    registerSetter(L, "mHeight", Terrain_set_mHeight);
    registerSetter(L, "mHeightScale", Terrain_set_mHeightScale);
    registerSetter(L, "mOffset", Terrain_set_mOffset);
    registerSetter(L, "mSizeScale", Terrain_set_mSizeScale);
    registerSetter(L, "mBuildCounter", Terrain_set_mBuildCounter);
    registerSetter(L, "mNeedsBuilding", Terrain_set_mNeedsBuilding);
    registerSetter(L, "mPatchesToBuild", Terrain_set_mPatchesToBuild);
    registerSetter(L, "mOnscreenLimit", Terrain_set_mOnscreenLimit);
    registerSetter(L, "mOffscreenLimit", Terrain_set_mOffscreenLimit);
    registerSetter(L, "mDrawableCount", Terrain_set_mDrawableCount);
    registerSetter(L, "mMaterialDistance", Terrain_set_mMaterialDistance);
    registerSetter(L, "mHeightCacheSize", Terrain_set_mHeightCacheSize);
    registerSetter(L, "mHeightCacheBox", Terrain_set_mHeightCacheBox);
    registerSetter(L, "mCachePositionX", Terrain_set_mCachePositionX);
    registerSetter(L, "mCachePositionY", Terrain_set_mCachePositionY);
    lua_setfield(L, -2, "__setters"); // Bind to metatable

    // Wire up inheritance to Ogre::MovableObject
    // setMetatableParent(L, TerrainBinding::getMetatableName(), Ogre::MovableObjectBinding::getMetatableName());

    lua_pop(L, 1); // Pop the metatable off the stack
}

} // namespace KenshiLua