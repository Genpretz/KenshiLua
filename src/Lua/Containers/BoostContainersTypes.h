#pragma once
#include "Lua/Containers/CommonTypes.h"
#include "kenshi/Tasker.h"
#include "kenshi/Animation/AnimationClass.h"
#include "kenshi/GameData.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/Gear.h"
#include "kenshi/Inventory.h"
#include "kenshi/Item.h"
#include "kenshi/gamedatamanager.h"
#include "kenshi/gui/MainBarGUI.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"

namespace KenshiLua
{
namespace Containers
{
typedef BoostUnorderedMapBinding<std::string, DatapanelGUI*> MainBarDatapanelsMapBinding;
typedef BoostUnorderedMapBinding<std::string, InventorySection*> BoostUnorderedMap_std_string_InventorySectionPtrBinding;
typedef BoostUnorderedMapBinding<std::string, Ogre::Quaternion> BoostUnorderedMap_std_string_Ogre_QuaternionBinding;
typedef BoostUnorderedMapBinding<std::string, Ogre::Vector3> BoostUnorderedMap_std_string_Ogre_Vector3Binding;
typedef BoostUnorderedMapBinding<std::string, bool> BoostUnorderedMap_std_string_boolBinding;
typedef BoostUnorderedMapBinding<std::string, float> BoostUnorderedMap_std_string_floatBinding;
typedef BoostUnorderedMapBinding<std::string, int> BoostUnorderedMap_std_string_intBinding;
typedef BoostUnorderedMapBinding<std::string, std::string> BoostUnorderedMap_std_string_std_stringBinding;
}
} // namespace KenshiLua
