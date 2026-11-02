#include "pch.h"
#include "Lua/LuaBindings.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"

namespace KenshiLua
{

void LuaBindings::registerContainers(lua_State* L)
{
    ContainerBindingList definitions;
    collectLektor(definitions);
    collectStdContainers(definitions);
    collectOgreUnordered(definitions);
    collectBoostContainers(definitions);
    collectArrays(definitions);
    collectFitnessSelectors(definitions);
    registerContainerBindings(L, definitions);
    registerLektorGlobal(L);
    registerOgreUnorderedGlobals(L);
}

} // namespace KenshiLua
