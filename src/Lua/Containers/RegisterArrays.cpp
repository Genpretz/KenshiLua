#include "pch.h"
#include "kenshi/Tasker.h"
#include "kenshi/Appearance.h"
#include "kenshi/GameData.h"
#include "kenshi/GameSaveState.h"
#include "kenshi/Inventory.h"
#include "kenshi/Item.h"
#include "kenshi/LocaleInfo.h"
#include "kenshi/ResourceLoader.h"
#include "kenshi/ShopTraderInventory.h"
#include "kenshi/Town.h"
#include "kenshi/gui/CharacterEditWindow.h"
#include "kenshi/gui/CharacterTradingWindow.h"
#include "kenshi/gui/DialogueWindow.h"
#include "kenshi/gui/MainBarGUI.h"
#include "kenshi/gui/MapScreen.h"
#include "kenshi/gui/TutorialGUI.h"
#include "Bindings/Kenshi/Animation/AnimationDataBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangeBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangePoseBinding.h"
#include "Bindings/Kenshi/Appearance/AppearanceManager_DataRangeVectorBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataReferenceBinding.h"
#include "Bindings/Kenshi/Gui/MainTabPortraitPlatoonBinding.h"
#include "Bindings/Kenshi/Gui/TutorialItemBinding.h"
#include "Bindings/Kenshi/Gui/TutorialSubItemBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/InventorySection_SectionItemBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/LocaleInfoBinding.h"
#include "Bindings/Kenshi/Util/Array2dBinding.h"
#include "Bindings/Kenshi/Util/OgreFastArrayBinding.h"
#include "Bindings/Kenshi/Util/OgreVectorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/Util/TagsClassBinding.h"
#include "Lua/LuaBindings.h"

#include "Lua/ContainerBinding.h"
#include "Lua/Containers/ArraysTypes.h"

namespace KenshiLua
{

KENSHILUA_DEFINE_CONTAINER(Containers::Array2d_ItemBinding, "KenshiLua.Array2d<Item>",
    ItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::OgreVectorValue_StringPairBinding, "KenshiLua.OgreVectorStringPair",
    StringPairBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TownFacilitiesTagsBinding, "KenshiLua.TagsClass<BuildingDesignation>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::AnimationDataFastArrayBinding, "Ogre::FastArray<AnimationData*>",
    AnimationDataBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::AttachedEffectFastArrayBinding, "Ogre::FastArray<AttachedEffect*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::CharacterFastArrayBinding, "Ogre::FastArray<Character*>",
    CharacterBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::CharacterTradingBoxFastArrayBinding, "Ogre::FastArray<CharacterTradingBox*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::DataRangeFastArrayBinding, "Ogre::FastArray<DataRange>",
    AppearanceManager_DataRangeBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::DataRangePoseFastArrayBinding, "Ogre::FastArray<DataRangePose>",
    AppearanceManager_DataRangePoseBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::DataRangeVectorFastArrayBinding, "Ogre::FastArray<DataRangeVector>",
    AppearanceManager_DataRangeVectorBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::GameDataFastArrayBinding, "Ogre::FastArray<GameData*>",
    GameDataBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::HarpoonFastArrayBinding, "Ogre::FastArray<Harpoon*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::LocaleInfoPtrFastArrayBinding, "Ogre::FastArray<LocaleInfo*>",
    LocaleInfoBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::LocaleInfoValueFastArrayBinding, "Ogre::FastArray<LocaleInfo>",
    LocaleInfoBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TabPortraitsFastArrayBinding, "Ogre::FastArray<MainTabPortraitPlatoon>",
    MainTabPortraitPlatoonBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::SpeedButtonsFastArrayBinding, "Ogre::FastArray<MyGUI::Button*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::EditBoxFastArrayBinding, "Ogre::FastArray<MyGUI::EditBox*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::Vector3FastArrayBinding, "Ogre::FastArray<Ogre::Vector3>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::RaceGroupDataFastArrayBinding, "Ogre::FastArray<RaceGroupData*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TextureLoadDataFastArrayBinding, "Ogre::FastArray<TextureLoadData*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TutorialItemFastArrayBinding, "Ogre::FastArray<TutorialItem*>",
    TutorialItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::TutorialSubItemFastArrayBinding, "Ogre::FastArray<TutorialSubItem*>",
    TutorialSubItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::WoundFastArrayBinding, "Ogre::FastArray<Wound*>",
    nullptr, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::FloatFastArrayBinding, "Ogre::FastArray<float>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::HandFastArrayBinding, "Ogre::FastArray<hand>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::StringFastArrayBinding, "Ogre::FastArray<std::string>",
    NULL, NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::OgreVectorValue_GameDataReferenceBinding, "ogre_vector<GameDataReference>",
    GameDataReferenceBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::OgreVectorPtr_InventorySectionPtrBinding, "ogre_vector<InventorySection*>",
    InventorySectionBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

KENSHILUA_DEFINE_CONTAINER(Containers::InventorySectionItemsVectorBinding, "ogre_vector<InventorySection::SectionItem>",
    SectionItemBinding::getMetatableName(), NULL, NULL,
    ContainerFactoryDefinition())

void LuaBindings::collectArrays(ContainerBindingList& definitions)
{
    definitions.push_back(&containerBindingDefinition<Containers::Array2d_ItemBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreVectorValue_StringPairBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TownFacilitiesTagsBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::AnimationDataFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::AttachedEffectFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CharacterFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::CharacterTradingBoxFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::DataRangeFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::DataRangePoseFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::DataRangeVectorFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::GameDataFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HarpoonFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LocaleInfoPtrFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::LocaleInfoValueFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TabPortraitsFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::SpeedButtonsFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::EditBoxFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::Vector3FastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::RaceGroupDataFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TextureLoadDataFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TutorialItemFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::TutorialSubItemFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::WoundFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::FloatFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::HandFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::StringFastArrayBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreVectorValue_GameDataReferenceBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::OgreVectorPtr_InventorySectionPtrBinding::MetadataType>());
    definitions.push_back(&containerBindingDefinition<Containers::InventorySectionItemsVectorBinding::MetadataType>());
}

} // namespace KenshiLua
