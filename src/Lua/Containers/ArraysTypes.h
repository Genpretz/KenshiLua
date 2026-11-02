#pragma once
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
#include "Bindings/Kenshi/Util/Array2dBinding.h"
#include "Bindings/Kenshi/Util/OgreFastArrayBinding.h"
#include "Bindings/Kenshi/Util/OgreVectorBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/Util/TagsClassBinding.h"

namespace KenshiLua
{
namespace Containers
{
typedef Array2dBinding<Item> Array2d_ItemBinding;
typedef OgreVectorValueBinding<StringPair> OgreVectorValue_StringPairBinding;
typedef TagsClassBinding<BuildingDesignation> TownFacilitiesTagsBinding;
typedef OgreFastArrayPtrBinding<AnimationData*> AnimationDataFastArrayBinding;
typedef OgreFastArrayPtrBinding<AttachedEffect*> AttachedEffectFastArrayBinding;
typedef OgreFastArrayPtrBinding<Character*> CharacterFastArrayBinding;
typedef OgreFastArrayPtrBinding<CharacterTradingBox*> CharacterTradingBoxFastArrayBinding;
typedef OgreFastArrayValueBinding<AppearanceManager::DataRange> DataRangeFastArrayBinding;
typedef OgreFastArrayValueBinding<AppearanceManager::DataRangePose> DataRangePoseFastArrayBinding;
typedef OgreFastArrayValueBinding<AppearanceManager::DataRangeVector> DataRangeVectorFastArrayBinding;
typedef OgreFastArrayPtrBinding<GameData*> GameDataFastArrayBinding;
typedef OgreFastArrayPtrBinding<Harpoon*> HarpoonFastArrayBinding;
typedef OgreFastArrayPtrBinding<LocaleInfo*> LocaleInfoPtrFastArrayBinding;
typedef OgreFastArrayValueBinding<LocaleInfo> LocaleInfoValueFastArrayBinding;
typedef OgreFastArrayValueBinding<MainTabPortraitPlatoon> TabPortraitsFastArrayBinding;
typedef OgreFastArrayPtrBinding<MyGUI::Button*> SpeedButtonsFastArrayBinding;
typedef OgreFastArrayPtrBinding<MyGUI::EditBox*> EditBoxFastArrayBinding;
typedef OgreFastArrayValueBinding<Ogre::Vector3> Vector3FastArrayBinding;
typedef OgreFastArrayPtrBinding<RaceGroupData*> RaceGroupDataFastArrayBinding;
typedef OgreFastArrayPtrBinding<ResourceLoader::TextureLoadData*> TextureLoadDataFastArrayBinding;
typedef OgreFastArrayPtrBinding<TutorialItem*> TutorialItemFastArrayBinding;
typedef OgreFastArrayPtrBinding<TutorialSubItem*> TutorialSubItemFastArrayBinding;
typedef OgreFastArrayPtrBinding<Wound*> WoundFastArrayBinding;
typedef OgreFastArrayPrimitiveBinding<float> FloatFastArrayBinding;
typedef OgreFastArrayPrimitiveBinding<hand> HandFastArrayBinding;
typedef OgreFastArrayPrimitiveBinding<std::string> StringFastArrayBinding;
typedef OgreVectorValueBinding<GameDataReference> OgreVectorValue_GameDataReferenceBinding;
typedef OgreVectorPtrBinding<InventorySection*> OgreVectorPtr_InventorySectionPtrBinding;
typedef OgreVectorValueBinding<InventorySection::SectionItem> InventorySectionItemsVectorBinding;
}
} // namespace KenshiLua
