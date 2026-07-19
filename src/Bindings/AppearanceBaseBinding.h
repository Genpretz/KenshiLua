#pragma once

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AppearanceBaseBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AppearanceBase"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int _DESTRUCTOR(lua_State* L);
    static int updateAnimationTransforms(lua_State* L);
    static int forceUpdateAnimationTransforms(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int periodicUpdate(lua_State* L);
    static int _NV_periodicUpdate(lua_State* L);
    static int activate(lua_State* L);
    static int _NV_activate(lua_State* L);
    static int deactivate(lua_State* L);
    static int _NV_deactivate(lua_State* L);
    static int isFemale(lua_State* L);
    static int setGender(lua_State* L);
    static int _NV_setGender(lua_State* L);
    static int getRace(lua_State* L);
    static int detachAllHarpoonsT(lua_State* L);
    static int _detachAllHarpoons(lua_State* L);
    static int updateWetness(lua_State* L);
    static int updateBloodyness(lua_State* L);
    static int getAttachmentPosition(lua_State* L);
    static int hasSlot(lua_State* L);
    static int getNormalisedCharacterHeight(lua_State* L);
    static int getCharacterHeight(lua_State* L);
    static int getBodyRadius(lua_State* L);
    static int failedToLoad(lua_State* L);
    static int getBonePosition(lua_State* L);
    static int getBoneOrientation(lua_State* L);
    static int getVertexWorldPosition(lua_State* L);
    static int getRandomVertex(lua_State* L);
    static int notifyDirty(lua_State* L);
    static int reload(lua_State* L);
    static int updateAppearance(lua_State* L);
    static int _NV_updateAppearance(lua_State* L);
    static int updatePortrait(lua_State* L);
    static int updateMovementScale(lua_State* L);
    static int switchLights(lua_State* L);
    static int hasLights(lua_State* L);
    static int shaveHead(lua_State* L);
    static int isShaved(lua_State* L);
    static int setFlayed(lua_State* L);
    static int _NV_setFlayed(lua_State* L);
    static int isFlayed(lua_State* L);
    static int _NV_isFlayed(lua_State* L);
    static int isBarefoot(lua_State* L);
    static int _NV_isBarefoot(lua_State* L);
    static int setVisible(lua_State* L);
    static int getVisible(lua_State* L);
    static int getAttachmentsLoaded(lua_State* L);
    static int setAttachmentsVisible(lua_State* L);
    static int _NV_setAttachmentsVisible(lua_State* L);
    static int createBody(lua_State* L);
    static int buildAttachments(lua_State* L);
    static int setHairTexture(lua_State* L);
    static int updateOverlap(lua_State* L);
    static int updateCharaterTexture(lua_State* L);
    static int getCharacterHeightSpeedMultiplier(lua_State* L);
};
}
