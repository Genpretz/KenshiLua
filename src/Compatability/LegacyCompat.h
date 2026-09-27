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

        // Initializes all compatibility subsystems on a newly created Lua state.
        void Initialize(lua_State* L);
    }
}
