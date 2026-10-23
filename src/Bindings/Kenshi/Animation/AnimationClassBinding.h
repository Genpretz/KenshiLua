#pragma once
#include "kenshi/Animation/AnimationClass.h"

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

namespace KenshiLua
{
class AnimationClassBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.AnimationClass"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);

    static int debugGetAllAnimations(lua_State* L);
    static int endStumble(lua_State* L);
    static int currentlyStumbling(lua_State* L);
    static int isCurrentlyIncapableOfWaypointMovemode(lua_State* L);
    static int threadSafeRagdollUpdateUT(lua_State* L);
    static int update(lua_State* L);
    static int _NV_update(lua_State* L);
    static int calculatePositionWithWaterHeight(lua_State* L);
    static int updateAnimationCharacterEditor(lua_State* L);
    static int updateThreaded(lua_State* L);
    static int rotationUpdate(lua_State* L);
    static int _NV_rotationUpdate(lua_State* L);
    static int updateAnimationTransforms(lua_State* L);
    static int setPosition(lua_State* L);
    static int getPosition(lua_State* L);
    static int rotateEntityAroundBone(lua_State* L);
    static int getBoneScale(lua_State* L);
    static int deactivateVisuals(lua_State* L);
    static int getIsActivated(lua_State* L);
    static int resetBody(lua_State* L);
    static int restartAction(lua_State* L);
    static int playAction(lua_State* L);
    static int stopAction(lua_State* L);
    static int setAnimationMoveSpeed(lua_State* L);
    static int setStrafeSpeed(lua_State* L);
    static int setCombatMode(lua_State* L);
    static int setWeatherType(lua_State* L);
    static int getWeatherType(lua_State* L);
    static int getWeatherStrength(lua_State* L);
    static int setStealthMode(lua_State* L);
    static int setMaximumSpeed(lua_State* L);
    static int getMaximumSpeed(lua_State* L);
    static int isLinearAnimationDone_byName(lua_State* L);
    static int getFootHeight(lua_State* L);
    static int calculateFeetHeight(lua_State* L);
    static int setBootHeight(lua_State* L);
    static int isBeingCarried(lua_State* L);
    static int isTotallyRagdoll(lua_State* L);
    static int notifyRagdollNeedsAnUpdate(lua_State* L);
    static int setCarryMode(lua_State* L);
    static int setCombatModeLegsIdle(lua_State* L);
    static int setCombatModeUpperIdle(lua_State* L);
    static int isRagdoll(lua_State* L);
    static int ragdollAnimateTo(lua_State* L);
    static int isRagdollAnimated(lua_State* L);
    static int ragdollModeUT(lua_State* L);
    static int _NV_ragdollModeUT(lua_State* L);
    static int postRagdollCreationCallbackMT(lua_State* L);
    static int _NV_postRagdollCreationCallbackMT(lua_State* L);
    static int hasRagdollPart(lua_State* L);
    static int isPhysical(lua_State* L);
    static int getHeight(lua_State* L);
    static int randomiseAnimationPosition(lua_State* L);
    static int beingCarriedUpdate(lua_State* L);
    static int rangedCombatModeUpdate(lua_State* L);
    static int runAnimation(lua_State* L);
    static int endCombatAnimation(lua_State* L);
    static int runCombatAnimation(lua_State* L);
    static int startCombatAnimation(lua_State* L);
    static int startAnimation(lua_State* L);
    static int stopAnimation(lua_State* L);
    static int activateVisuals(lua_State* L);
    static int estimateAnimationTime(lua_State* L);
    static int notifyRelocatedAnimLoop(lua_State* L);
    static int serialiseAppearance(lua_State* L);
    static int setAppearanceData(lua_State* L);
    static int getAppearanceData(lua_State* L);
    static int getAudioObject(lua_State* L);
    static int _NV_getAudioObject(lua_State* L);
    static int playSlaveAnim(lua_State* L);
    static int runSlaveAnim(lua_State* L);
    static int endSlaveAnim(lua_State* L);
    static int isSlaveAnimating(lua_State* L);
    static int setSlaveHandle(lua_State* L);
    static int slaveAttachToBoneMode(lua_State* L);
    static int isSlaveAttachToBoneMode(lua_State* L);
    static int getCharacter(lua_State* L);
    static int _NV_getCharacter(lua_State* L);
    static int setLegDamage(lua_State* L);
    static int _NV_setLegDamage(lua_State* L);
    static int setDesiredPainOverlayAnimOverride(lua_State* L);
    static int _NV_setDesiredPainOverlayAnimOverride(lua_State* L);
    static int ragdollTheWeapons(lua_State* L);
    static int _NV_ragdollTheWeapons(lua_State* L);
    static int setStance(lua_State* L);
    static int _NV_setStance(lua_State* L);
    static int setStanceAnimation(lua_State* L);
    static int _NV_setStanceAnimation(lua_State* L);
    static int setEquipmentInHand(lua_State* L);
    static int _NV_setEquipmentInHand(lua_State* L);
    static int isTurning(lua_State* L);
    static int _NV_isTurning(lua_State* L);
    static int isTurningFar(lua_State* L);
    static int _NV_isTurningFar(lua_State* L);
    static int lookAt(lua_State* L);
    static int _NV_lookAt(lua_State* L);
    static int getLookDirection(lua_State* L);
    static int _NV_getLookDirection(lua_State* L);
    static int hasAction(lua_State* L);
    static int animationSelection(lua_State* L);
    static int animationSelectionCombatMode(lua_State* L);
    static int _NV_animationSelectionCombatMode(lua_State* L);
    static int overlaidAnimationSelection(lua_State* L);
    static int _NV_overlaidAnimationSelection(lua_State* L);
    static int processTurnAnim(lua_State* L);
    static int _NV_processTurnAnim(lua_State* L);
    static int breathing(lua_State* L);
    static int _NV_breathing(lua_State* L);
};
}
