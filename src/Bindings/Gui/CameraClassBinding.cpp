#include "pch.h"
#include "Bindings/Gui/CameraClassBinding.h"
#include "Bindings/Core/RootObjectBinding.h"
#include "Bindings/Utility/HandBinding.h"
#include "Bindings/Character/CharacterBinding.h"
#include "Bindings/Building/BuildingBinding.h"
#include "Bindings/Equipment/ItemBinding.h"
#include "Bindings/Core/GameDataBinding.h"
#include "Lua/BindingHelpers.h"

#include <kenshi/CameraClass.h>
#include <kenshi/RootObject.h>
#include <kenshi/Character.h>
#include <kenshi/Building/Building.h>
#include <kenshi/Item.h>
#include <kenshi/util/hand.h>
#include <kenshi/GameData.h>

#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

#include <cstdio>
#include <cstring>

namespace KenshiLua
{

static CameraClass* getCam(lua_State* L, int idx)
{
    return checkObject<CameraClass>(L, idx, CameraClassBinding::getMetatableName());
}

int CameraClassBinding::gc(lua_State* L) { return noopGc(L); }

int CameraClassBinding::tostring(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushstring(L, "CameraClass:nil"); return 1; }
    char buf[160];
    _snprintf(buf, sizeof(buf), "CameraClass(%p)", (void*)c);
    lua_pushstring(L, buf);
    return 1;
}

int CameraClassBinding::index(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);

    luaL_getmetatable(L, CameraClassBinding::getMetatableName());
    lua_getfield(L, -1, key);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }

    // --- boolean members ---
    if (strcmp(key, "freeCameraMode") == 0) { lua_pushboolean(L, c->freeCameraMode ? 1 : 0); return 1; }
    if (strcmp(key, "isRotating") == 0) { lua_pushboolean(L, c->isRotating ? 1 : 0); return 1; }
    if (strcmp(key, "initialised") == 0) { lua_pushboolean(L, c->initialised ? 1 : 0); return 1; }
    if (strcmp(key, "terrainLoaded") == 0) { lua_pushboolean(L, c->terrainLoaded ? 1 : 0); return 1; }

    // --- float members ---
    if (strcmp(key, "yaw") == 0) { lua_pushnumber(L, c->yaw); return 1; }
    if (strcmp(key, "pitch") == 0) { lua_pushnumber(L, c->pitch); return 1; }
    if (strcmp(key, "altitude") == 0) { lua_pushnumber(L, c->altitude); return 1; }
    if (strcmp(key, "timeInGame") == 0) { lua_pushnumber(L, c->timeInGame); return 1; }
    if (strcmp(key, "targetPositionY") == 0) { lua_pushnumber(L, c->targetPositionY); return 1; }
    if (strcmp(key, "speedY") == 0) { lua_pushnumber(L, c->speedY); return 1; }
    if (strcmp(key, "centerBuildingY") == 0) { lua_pushnumber(L, c->centerBuildingY); return 1; }

    // --- int members ---
    if (strcmp(key, "currentMusic") == 0) { lua_pushnumber(L, c->currentMusic); return 1; }

    // --- hand members ---
    if (strcmp(key, "objectCurrentlyFollowing") == 0)
    {
        return HandBinding::pushHand(L, c->objectCurrentlyFollowing);
    }
    if (strcmp(key, "inBuilding") == 0)
    {
        return HandBinding::pushHand(L, c->inBuilding);
    }

    // --- Ogre::Vector3 members ---
    if (strcmp(key, "objectCurrentlyFollowingOffset") == 0)
    {
        pushVector3(L, c->objectCurrentlyFollowingOffset);
        return 1;
    }

    // --- pointer members ---
    if (strcmp(key, "rotationMarker") == 0) { lua_pushlightuserdata(L, (void*)c->rotationMarker); return 1; }
    if (strcmp(key, "center") == 0) { lua_pushlightuserdata(L, (void*)c->center); return 1; }
    if (strcmp(key, "camera") == 0) { lua_pushlightuserdata(L, (void*)c->camera); return 1; }
    if (strcmp(key, "node") == 0) { lua_pushlightuserdata(L, (void*)c->node); return 1; }

    if (strcmp(key, "centerBuilding") == 0) {
        return pushObject<Building>(L, c->centerBuilding, BuildingBinding::getMetatableName());
    }

    lua_pushnil(L);
    return 1;
}

int CameraClassBinding::newindex(lua_State* L)
{
    const char* key = luaL_checkstring(L, 2);
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");

    // --- writable properties ---
    if (strcmp(key, "freeCameraMode") == 0) {
        c->setFreeCameraMode(lua_toboolean(L, 3) != 0);
        return 0;
    }
    // --- boolean members ---
    if (strcmp(key, "freeCameraMode") == 0) { c->freeCameraMode = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "isRotating") == 0) { c->isRotating = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "initialised") == 0) { c->initialised = (lua_toboolean(L, 3) != 0); return 0; }
    if (strcmp(key, "terrainLoaded") == 0) { c->terrainLoaded = (lua_toboolean(L, 3) != 0); return 0; }

    // --- float members ---
    if (strcmp(key, "yaw") == 0) { c->yaw = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "pitch") == 0) { c->pitch = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "altitude") == 0) { c->altitude = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "timeInGame") == 0) { c->timeInGame = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "targetPositionY") == 0) { c->targetPositionY = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "speedY") == 0) { c->speedY = (float)luaL_checknumber(L, 3); return 0; }
    if (strcmp(key, "centerBuildingY") == 0) { c->centerBuildingY = (float)luaL_checknumber(L, 3); return 0; }

    // --- Ogre::Vector3 members ---
    if (strcmp(key, "objectCurrentlyFollowingOffset") == 0) {
        if (!readVector3(L, 3, c->objectCurrentlyFollowingOffset))
            return luaL_error(L, "objectCurrentlyFollowingOffset: expected Vector3 {x,y,z}");
        return 0;
    }

    // --- read-only members ---
    if (strcmp(key, "rotationMarker") == 0) { return luaL_error(L, "CameraClass: field '%s' is read-only", key); }
    if (strcmp(key, "center") == 0) { return luaL_error(L, "CameraClass: field '%s' is read-only", key); }
    if (strcmp(key, "camera") == 0) { return luaL_error(L, "CameraClass: field '%s' is read-only", key); }
    if (strcmp(key, "node") == 0) { return luaL_error(L, "CameraClass: field '%s' is read-only", key); }

    // --- pointer members ---
    if (strcmp(key, "centerBuilding") == 0)
    {
        c->centerBuilding = checkObject<Building>(L, 3, BuildingBinding::getMetatableName());
        return 0;
    }
    // if (strcmp(key, "centerBuilding") == 0)
    // {
    //     return luaL_error(L,"CameraClass: field '%s' is read-only",key);
    // }

    return luaL_error(L, "CameraClass: field '%s' is read-only or does not exist", key);
}

int CameraClassBinding::focusCameraOnObject(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");

    // Can accept Character, Item, Building or RootObject userdata (all cast to RootObject*)
    RootObject* obj = testObject<RootObject>(L, 2, RootObjectBinding::getMetatableName());
    if (obj == 0)
    {
        // Try other related metatables since they are subclasses of RootObject
        obj = (RootObject*)testObject<Character>(L, 2, CharacterBinding::getMetatableName());
        if (obj == 0)
        {
            obj = (RootObject*)testObject<Building>(L, 2, BuildingBinding::getMetatableName());
            if (obj == 0)
            {
                obj = (RootObject*)testObject<Item>(L, 2, ItemBinding::getMetatableName());
            }
        }
    }
    if (obj == 0) return luaL_error(L, "focusCameraOnObject: expected RootObject/Character/Building/Item userdata");

    Ogre::Vector3 offset(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 3, offset)) return luaL_error(L, "focusCameraOnObject: expected Vector3 offset {x,y,z}");

    bool nearZoom = lua_toboolean(L, 4) != 0;

    c->focusCameraOnObject(obj, offset, nearZoom);
    return 0;
}

int CameraClassBinding::update(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    bool controlEnabled = lua_toboolean(L, 2) != 0;
    c->update(controlEnabled);
    return 0;
}

int CameraClassBinding::save(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (data == 0) return luaL_error(L, "save: expected GameData userdata");
    c->save(data);
    return 0;
}

int CameraClassBinding::load(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    GameData* data = checkObject<GameData>(L, 2, GameDataBinding::getMetatableName());
    if (data == 0) return luaL_error(L, "load: expected GameData userdata");
    c->load(data);
    return 0;
}

int CameraClassBinding::reset(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->reset();
    return 0;
}

int CameraClassBinding::isVisible(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (!c)
        return luaL_error(L, "CameraClass is nil");

    Ogre::Vector3 pos;
    if (!readVector3(L, 2, pos))
        return luaL_error(L, "isVisible: expected Vector3 {x,y,z}");

    bool visible;

    if (lua_gettop(L) >= 3)
    {
        float radius = (float)luaL_checknumber(L, 3);
        visible = c->isVisible(pos, radius);
    }
    else
    {
        visible = c->isVisible(pos);
    }

    lua_pushboolean(L, visible);
    return 1;
}

int CameraClassBinding::intersectScreenEdge(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    Ogre::Vector3 a(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, a)) return luaL_error(L, "intersectScreenEdge: expected Vector3 {x,y,z}");
    Ogre::Vector3 b(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 3, b)) return luaL_error(L, "intersectScreenEdge: expected Vector3 {x,y,z}");
    float padding = (float)luaL_optnumber(L, 4, 0.0f);
    float out = 0.0f;
    int result = c->intersectScreenEdge(a, b, padding, out);
    lua_pushnumber(L, result);
    lua_pushnumber(L, out);
    return 2;
}

int CameraClassBinding::teleport(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    Ogre::Vector3 pos(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, pos)) return luaL_error(L, "teleport: expected Vector3 {x,y,z}");
    c->teleport(pos);
    return 0;
}

int CameraClassBinding::followObject(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    hand* h = (hand*)luaL_checkudata(L, 2, HandBinding::getMetatableName());
    if (h == 0) return luaL_error(L, "followObject: expected hand userdata");
    c->followObject(*h);
    return 0;
}

int CameraClassBinding::stopFollowing(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c != 0) c->stopFollowing();
    return 0;
}

int CameraClassBinding::getFollowObject(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }
    return HandBinding::pushHand(L, c->getFollowObject());
}

int CameraClassBinding::manuallySetOrientationAndZoom(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");

    // Read orientation Quaternion from table
    float qw = (float)luaL_optnumber(L, 2, 1.0);
    float qx = (float)luaL_optnumber(L, 3, 0.0);
    float qy = (float)luaL_optnumber(L, 4, 0.0);
    float qz = (float)luaL_optnumber(L, 5, 0.0);
    Ogre::Quaternion rot(qw, qx, qy, qz);

    float zoom = (float)luaL_checknumber(L, 6);

    c->manuallySetOrientationAndZoom(rot, zoom);
    return 0;
}

int CameraClassBinding::getFacingDirection(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }
    pushVector3(L, c->getFacingDirection());
    return 1;
}

int CameraClassBinding::getCenter(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }
    pushVector3(L, c->getCenter());
    return 1;
}

int CameraClassBinding::getCameraPos(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }
    pushVector3(L, c->getCameraPos());
    return 1;
}

int CameraClassBinding::isFreeCameraMode(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) { lua_pushnil(L); return 1; }
    lua_pushboolean(L, c->isFreeCameraMode() ? 1 : 0);
    return 1;
}

int CameraClassBinding::setFreeCameraMode(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->setFreeCameraMode(lua_toboolean(L, 2) != 0);
    return 0;
}

int CameraClassBinding::updateOptionSettings(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->updateOptionSettings();
    return 0;
}

int CameraClassBinding::move(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    Ogre::Vector3 dir(0.0f, 0.0f, 0.0f);
    if (!readVector3(L, 2, dir)) return luaL_error(L, "move: expected Vector3 {x,y,z}");
    c->move(dir);
    return 0;
}

int CameraClassBinding::zoom(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->zoom();
    return 0;
}

int CameraClassBinding::toGround(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    bool smooth = lua_toboolean(L, 2) != 0;
    c->toGround(smooth);
    return 0;
}

int CameraClassBinding::setZoomDist(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    float dist = (float)luaL_checknumber(L, 2);
    c->setZoomDist(dist);
    return 0;
}

int CameraClassBinding::rotate(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    float yaw = (float)luaL_checknumber(L, 2);
    float pitch = (float)luaL_checknumber(L, 3);
    c->rotate(yaw, pitch);
    return 0;
}

int CameraClassBinding::rotationUpdate(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->rotationUpdate();
    return 0;
}

int CameraClassBinding::updateAudio(lua_State* L)
{
    CameraClass* c = getCam(L, 1);
    if (c == 0) return luaL_error(L, "CameraClass is nil");
    c->updateAudio();
    return 0;
}

void CameraClassBinding::registerBinding(lua_State* L)
{
    static const luaL_Reg meta[] = {
        { "__gc",       CameraClassBinding::gc },
        { "__tostring", CameraClassBinding::tostring },
        { 0, 0 }
    };
    static const luaL_Reg methods[] = {
        { "save",                           CameraClassBinding::save },
        { "load",                           CameraClassBinding::load },
        { "reset",                          CameraClassBinding::reset },
        { "update",                         CameraClassBinding::update },
        { "updateOptionSettings",             CameraClassBinding::updateOptionSettings },
        { "isVisible",                        CameraClassBinding::isVisible },
        { "intersectScreenEdge",            CameraClassBinding::intersectScreenEdge },
        { "focusCameraOnObject",            CameraClassBinding::focusCameraOnObject },
        { "teleport",                       CameraClassBinding::teleport },
        { "followObject",                   CameraClassBinding::followObject },
        { "stopFollowing",                  CameraClassBinding::stopFollowing },
        { "getFollowObject",                CameraClassBinding::getFollowObject },
        { "manuallySetOrientationAndZoom",   CameraClassBinding::manuallySetOrientationAndZoom },
        { "getFacingDirection",             CameraClassBinding::getFacingDirection },
        { "getCenter",                      CameraClassBinding::getCenter },
        { "getCameraPos",                   CameraClassBinding::getCameraPos },
        { "isFreeCameraMode",               CameraClassBinding::isFreeCameraMode },
        { "setFreeCameraMode",              CameraClassBinding::setFreeCameraMode },
        { "move",                           CameraClassBinding::move },
        { "zoom",                           CameraClassBinding::zoom },
        { "toGround",                       CameraClassBinding::toGround },
        { "setZoomDist",                    CameraClassBinding::setZoomDist },
        { "rotate",                         CameraClassBinding::rotate },
        { "rotationUpdate",                 CameraClassBinding::rotationUpdate },
        { "updateAudio",                    CameraClassBinding::updateAudio },
        { 0, 0 }
    };
    registerClass(L, CameraClassBinding::getMetatableName(), meta, methods, CameraClassBinding::index, CameraClassBinding::newindex);
}

} // namespace KenshiLua