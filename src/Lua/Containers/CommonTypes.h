#pragma once
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"

class GameData;
class AnimationData;
class RootObject;
class NestBatcher;

namespace KenshiLua
{
namespace Containers
{
typedef StdMapBinding<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool>>> StdMap_GameDataPtr_boolBinding;
typedef StdMapBinding<GameData*, hand, std::less<GameData*>, std::allocator<std::pair<GameData* const, hand> >> GameDataHandMapBinding;
typedef StdDequePtrBinding<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy>> KillListPhase2DequeBinding;
typedef StdDequePtrBinding<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy>> NestBatcherKillListDequeBinding;
typedef BoostUnorderedMapBinding<std::string, AnimationData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<std::string const, AnimationData*>, Ogre::GeneralAllocPolicy>> AnimStringMapBinding;
typedef BoostUnorderedMapBinding<std::string, GameData*, boost::hash<std::string>, std::equal_to<std::string>, Ogre::STLAllocator<std::pair<const std::string, GameData*>, Ogre::GeneralAllocPolicy>> BoostUnorderedMap_std_string_GameDataPtrBinding;
}
} // namespace KenshiLua
