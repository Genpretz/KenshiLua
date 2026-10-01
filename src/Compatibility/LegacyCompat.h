#pragma once

struct lua_State;

namespace KenshiLua
{
    namespace LegacyCompat
    {
        // Resolves a legacy event name (e.g. "onCharacterDeath", "chooseAttack", "onActivePlatoonConstructed")
        // to its canonical C++ scoped symbol ("Character::declareDead", "CharStats::chooseAttack", "ActivePlatoon::_CONSTRUCTOR").
        // If the event is already canonical or unrecognized, returns rawEventName unchanged.
        // Logs an advisory deprecation warning when a legacy name is resolved.
        const char* ResolveEventName(const char* rawEventName, const char* source = "");

        // Installs MyGUI backward compatibility:
        // - Global MyGUI convenience helpers (resetKeyFocus, setPointerVisible, isResourceExist, loadResource, createWidget adapter)
        // - Widget relative sizing/positioning methods (setPositionReal, setCoordReal, getImageSize, setImageInfo, setImageRect, attachToWidget, detachFromWidget)
        // - Monolithic widget property fallbacks on KenshiLua.MyGUI.Widget (setFontName, setEditReadOnly, setMinSize, setImageTexture, etc.)
        void InstallMyGUICompatibility(lua_State* L);

        // Initializes all compatibility subsystems on a newly created Lua state.
        void Initialize(lua_State* L);
    }
}
