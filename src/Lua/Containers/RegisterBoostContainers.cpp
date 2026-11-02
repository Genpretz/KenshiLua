#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/Animation/AnimationClass.h"
#include "kenshi/GameData.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/Gear.h"
#include "kenshi/Inventory.h"
#include "kenshi/Item.h"
#include "kenshi/gamedatamanager.h"
#include "kenshi/gui/MainBarGUI.h"
#include "Bindings/Kenshi/Animation/AnimationDataBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/Util/BoostUnorderedBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/BoostContainersTypes.h"

namespace KenshiLua
{

KENSHILUA_DEFINE_CONTAINER(Containers::MainBarDatapanelsMapBinding, "boost::unordered_map<std::string, DatapanelGUI*>",
    nullptr, DatapanelGUIBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::AnimStringMapBinding, "boost_unordered_map<std::string, AnimationData*>",
    nullptr, AnimationDataBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_GameDataPtrBinding, "boost_unordered_map<std::string, GameData*>",
    nullptr, GameDataBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_InventorySectionPtrBinding, "boost_unordered_map<std::string, InventorySection*>",
    nullptr, InventorySectionBinding::getMetatableName(), NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_Ogre_QuaternionBinding, "boost_unordered_map<std::string, Quaternion>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_Ogre_Vector3Binding, "boost_unordered_map<std::string, Vector3>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_boolBinding, "boost_unordered_map<std::string, bool>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_floatBinding, "boost_unordered_map<std::string, float>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_intBinding, "boost_unordered_map<std::string, int>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::BoostUnorderedMap_std_string_std_stringBinding, "boost_unordered_map<std::string, std::string>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

static_assert(std::is_same<Containers::AnimStringMapBinding::ContainerType,
    decltype(((AnimsListsManager::AnimList*)0)->allAnims)>::value, "AnimsListsManager::AnimList::allAnims container type mismatch");
static_assert(std::is_same<Containers::BoostUnorderedMap_std_string_GameDataPtrBinding::ContainerType,
    decltype(((GameDataContainer*)0)->gamedataSID)>::value, "GameDataContainer::gamedataSID container type mismatch");

void LuaBindings::collectBoostContainers(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::MainBarDatapanelsMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::AnimStringMapBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_GameDataPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_InventorySectionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_Ogre_QuaternionBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_Ogre_Vector3Binding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_boolBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_floatBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_intBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::BoostUnorderedMap_std_string_std_stringBinding::MetadataType>());
}

} // namespace KenshiLua
