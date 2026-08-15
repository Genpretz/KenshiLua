#pragma once
namespace KenshiLua
{
class ZoneManager_BiomeGroundEffectsBinding
{
public:
    static const char* getMetatableName() { return "KenshiLua.ZoneManager_BiomeGroundEffects"; }
    static void registerBinding(lua_State* L);

    static int gc(lua_State* L);
    static int tostring(lua_State* L);
    static int operator_eq(lua_State* L);
};
} // namespace KenshiLua
