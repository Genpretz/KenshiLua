#include "pch.h"
#include "Lua/LuaBindings.h"

#include "Bindings/Kenshi/Building/BuildingBinding.h"
#include "Bindings/Kenshi/Building/CraftingItemBinding.h"
#include "Bindings/Kenshi/Building/FarmBuildingBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantBinding.h"
#include "Bindings/Kenshi/Building/FarmBuilding_PlantSourceBinding.h"
#include "Bindings/Kenshi/Building/GameDataGroupBinding.h"
#include "Bindings/Kenshi/CampaignDataBinding.h"
#include "Bindings/Kenshi/CampaignInstanceBinding.h"
#include "Bindings/Kenshi/CharacterBinding.h"
#include "Bindings/Kenshi/Character_RagdollMsgBinding.h"
#include "Bindings/Kenshi/CombatTechniqueDataBinding.h"
#include "Bindings/Kenshi/CreatelistItemBinding.h"
#include "Bindings/Kenshi/DialogActionBinding.h"
#include "Bindings/Kenshi/DialogConditionBinding.h"
#include "Bindings/Kenshi/DialogLineDataBinding.h"
#include "Bindings/Kenshi/EnumBinding.h"
#include "Bindings/Kenshi/FactionBinding.h"
#include "Bindings/Kenshi/Faction_BuildingSwapsBinding.h"
#include "Bindings/Kenshi/FitnessSelectorBinding.h"
#include "Bindings/Kenshi/GameDataBinding.h"
#include "Bindings/Kenshi/GameDataValuePairBinding.h"
#include "Bindings/Kenshi/Gui/DatapanelGUIBinding.h"
#include "Bindings/Kenshi/Gui/GUIWindowBinding.h"
#include "Bindings/Kenshi/Gui/ScreenLabelInterfaceBinding.h"
#include "Bindings/Kenshi/InventorySectionBinding.h"
#include "Bindings/Kenshi/ItemBinding.h"
#include "Bindings/Kenshi/ModInfoBinding.h"
#include "Bindings/Kenshi/ObjectInstanceBinding.h"
#include "Bindings/Kenshi/PlatoonBinding.h"
#include "Bindings/Kenshi/RootObjectBinding.h"
#include "Bindings/Kenshi/SaveInfoBinding.h"
#include "Bindings/Kenshi/TaskerBinding.h"
#include "Bindings/Kenshi/TownBaseBinding.h"
#include "Bindings/Kenshi/Util/HandBinding.h"
#include "Bindings/Kenshi/Util/LektorBinding.h"
#include "Bindings/Kenshi/Util/OgreUnorderedBinding.h"
#include "Bindings/Kenshi/Util/StdDequeBinding.h"
#include "Bindings/Kenshi/Util/StdMapBinding.h"
#include "Bindings/Kenshi/Util/StdSetBinding.h"
#include "Bindings/Kenshi/Util/StringPairBinding.h"
#include "Bindings/Kenshi/WorldEventStateQueryBinding.h"
#include "Bindings/Kenshi/ZoneManagerBinding.h"
#include "Bindings/Kenshi/ZoneMapBinding.h"

namespace KenshiLua
{

void LuaBindings::registerLektor(lua_State* L)
{
    LektorPtrBinding<Character*>::registerBinding(L, "lektor<Character*>", CharacterBinding::getMetatableName());
    LektorPtrBinding<ModInfo*>::registerBinding(L, "lektor<ModInfo*>", ModInfoBinding::getMetatableName());
    LektorPtrBinding<GameData::ObjectInstance*>::registerBinding(L, "lektor<GameData::ObjectInstance*>", ObjectInstanceBinding::getMetatableName());
    LektorPtrBinding<GameData*>::registerBinding(L, "lektor<GameData*>", GameDataBinding::getMetatableName());
    LektorPtrBinding<DialogLineData::DialogCondition*>::registerBinding(L, "lektor<DialogCondition*>", DialogConditionBinding::getMetatableName());
    LektorPtrBinding<DialogLineData::DialogAction*>::registerBinding(L, "lektor<DialogAction*>", DialogActionBinding::getMetatableName());
    LektorPtrBinding<DialogLineData*>::registerBinding(L, "lektor<DialogLineData*>", DialogLineDataBinding::getMetatableName());
    LektorPtrBinding<CombatTechniqueData*>::registerBinding(L, "lektor<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName());
    LektorPtrBinding<Item*>::registerBinding(L, "lektor<Item*>", ItemBinding::getMetatableName());
    LektorPtrBinding<InventorySection*>::registerBinding(L, "lektor<InventorySection*>", InventorySectionBinding::getMetatableName());
    LektorPtrBinding<RootObject*>::registerBinding(L, "lektor<RootObject*>", RootObjectBinding::getMetatableName());
    LektorPtrBinding<Building*>::registerBinding(L, "lektor<Building*>", BuildingBinding::getMetatableName());
    LektorPtrBinding<FarmBuilding*>::registerBinding(L, "lektor<FarmBuilding*>", FarmBuildingBinding::getMetatableName());
    LektorPtrBinding<FarmBuilding::PlantSource*>::registerBinding(L, "lektor<FarmBuilding::PlantSource*>", FarmBuilding_PlantSourceBinding::getMetatableName());
    LektorPtrBinding<TownBase*>::registerBinding(L, "lektor<TownBase*>", TownBaseBinding::getMetatableName());
    LektorPtrBinding<DatapanelGUI*>::registerBinding(L, "lektor<DatapanelGUI*>", DatapanelGUIBinding::getMetatableName());
    LektorPtrBinding<GUIWindow*>::registerBinding(L, "lektor<GUIWindow*>", GUIWindowBinding::getMetatableName());
    LektorPtrBinding<ScreenLabelInterface*>::registerBinding(L, "lektor<ScreenLabelInterface*>", ScreenLabelInterfaceBinding::getMetatableName());
    LektorPtrBinding<CampaignInstance*>::registerBinding(L, "lektor<CampaignInstance*>", CampaignInstanceBinding::getMetatableName());
    LektorPtrBinding<CampaignData*>::registerBinding(L, "lektor<CampaignData*>", CampaignDataBinding::getMetatableName());

    LektorValueBinding<ModInfo>::registerBinding(L, "lektor<ModInfo>", ModInfoBinding::getMetatableName());
    LektorValueBinding<hand>::registerBinding(L, "lektor<hand>", HandBinding::getMetatableName());
    LektorValueBinding<SaveInfo>::registerBinding(L, "lektor<SaveInfo>", SaveInfoBinding::getMetatableName());
    LektorValueBinding<StringPair>::registerBinding(L, "lektor<StringPair>", StringPairBinding::getMetatableName());
    LektorValueBinding<Faction::BuildingSwaps>::registerBinding(L, "lektor<Faction::BuildingSwaps>", BuildingSwapsBinding::getMetatableName());
    LektorValueBinding<FarmBuilding::Plant>::registerBinding(L, "lektor<FarmBuilding::Plant>", FarmBuilding_PlantBinding::getMetatableName());

    LektorValueReadOnlyBinding<GameDataValuePair>::registerBinding(L, "lektor<GameDataValuePair>", GameDataValuePairBinding::getMetatableName());
    LektorValueReadOnlyBinding<GameDataGroup>::registerBinding(L, "lektor<GameDataGroup>", GameDataGroupBinding::getMetatableName());

    LektorStringBinding<std::string>::registerBinding(L, "lektor<std::string>");
    LektorIntBinding<int>::registerBinding(L, "lektor<int>");

    registerLektorGlobal(L);
}

void LuaBindings::registerOgreUnordered(lua_State* L)
{
    OgreUnorderedSetBinding<hand>::registerBinding(L, "ogre_unordered_set<hand>", HandBinding::getMetatableName());
    OgreUnorderedSetBinding<GameData*>::registerBinding(L, "ogre_unordered_set<GameData*>", GameDataBinding::getMetatableName());
    OgreUnorderedSetBinding<TownBase*>::registerBinding(L, "ogre_unordered_set<TownBase*>", TownBaseBinding::getMetatableName());
    OgreUnorderedSetBinding<Character*>::registerBinding(L, "ogre_unordered_set<Character*>", CharacterBinding::getMetatableName());
    OgreUnorderedSetBinding<RootObject*>::registerBinding(L, "ogre_unordered_set<RootObject*>", RootObjectBinding::getMetatableName());
    OgreUnorderedSetBinding<ZoneMap*>::registerBinding(L, "ogre_unordered_set<ZoneMap*>", ZoneMapBinding::getMetatableName());

    OgreUnorderedMapBinding<RootObject*, float>::registerBinding(L, "ogre_unordered_map<RootObject*, float>", RootObjectBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<Character*, float>::registerBinding(L, "ogre_unordered_map<Character*, float>", CharacterBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, float>::registerBinding(L, "ogre_unordered_map<hand, float>", HandBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<hand, Character*>::registerBinding(L, "ogre_unordered_map<hand, Character*>", HandBinding::getMetatableName(), CharacterBinding::getMetatableName());
    OgreUnorderedMapBinding<GameData*, float>::registerBinding(L, "ogre_unordered_map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, unsigned char>::registerBinding(L, "ogre_unordered_map<ZoneMap*, unsigned char>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<ZoneMap*, bool>::registerBinding(L, "ogre_unordered_map<ZoneMap*, bool>", ZoneMapBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<Faction*, bool>::registerBinding(L, "ogre_unordered_map<Faction*, bool>", FactionBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<GameData*, WorldStateEnum>::registerBinding(L, "ogre_unordered_map<GameData*, WorldStateEnum>", GameDataBinding::getMetatableName(), nullptr);
    OgreUnorderedMapBinding<WorldEventStateQuery*, bool>::registerBinding(L, "ogre_unordered_map<WorldEventStateQuery*, bool>", WorldEventStateQueryBinding::getMetatableName(), nullptr);

    registerOgreUnorderedGlobals(L);
}

void LuaBindings::registerStdSet(lua_State* L)
{
    StdSetBinding<hand>::registerBinding(L, "std::set<hand>", HandBinding::getMetatableName());
    StdSetBinding<Faction*>::registerBinding(L, "std::set<Faction*>", FactionBinding::getMetatableName());
    StdSetBinding<GameData*>::registerBinding(L, "std::set<GameData*>", GameDataBinding::getMetatableName());
}

void LuaBindings::registerStdMap(lua_State* L)
{
    StdMapBinding<float, CombatTechniqueData*>::registerBinding(L, "std::map<float, CombatTechniqueData*>", nullptr, CombatTechniqueDataBinding::getMetatableName());
    StdMapBinding<CombatTechniqueData*, float>::registerBinding(L, "std::map<CombatTechniqueData*, float>", CombatTechniqueDataBinding::getMetatableName(), nullptr);
    StdMapBinding<float, GameData*>::registerBinding(L, "std::map<float, GameData*>", nullptr, GameDataBinding::getMetatableName());
    StdMapBinding<GameData*, float>::registerBinding(L, "std::map<GameData*, float>", GameDataBinding::getMetatableName(), nullptr);
    StdMapBinding<GameData*, bool, std::less<GameData*>, std::allocator<std::pair<GameData* const, bool>>>::registerBinding(L, "std::map<GameData*, bool>", GameDataBinding::getMetatableName(), nullptr);
    StdMapBinding<std::string, Ogre::Quaternion>::registerBinding(L, "std::map<std::string, Quaternion>");
    StdMapBinding<Platoon*, CampaignInstance*>::registerBinding(L, "std::map<Platoon*, CampaignInstance*>", PlatoonBinding::getMetatableName(), CampaignInstanceBinding::getMetatableName());
    StdMapBinding<float, Tasker*>::registerBinding(L, "std::map<float, Tasker*>", nullptr, TaskerBinding::getMetatableName());
}

void LuaBindings::registerStdDeque(lua_State* L)
{
    StdDequePtrBinding<RootObject*, Ogre::STLAllocator<RootObject*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<RootObject*>", RootObjectBinding::getMetatableName());
    StdDequePtrBinding<NestBatcher*, Ogre::STLAllocator<NestBatcher*, Ogre::GeneralAllocPolicy>>::registerBinding(L, "std::deque<NestBatcher*>", nullptr);
    StdDequePtrBinding<RootObjectFactory::CreatelistItem*>::registerBinding(L, "std::deque<CreatelistItem*>", CreatelistItemBinding::getMetatableName());
    StdDequeValueReadOnlyBinding<CraftingItem>::registerBinding(L, "std::deque<CraftingItem>", CraftingItemBinding::getMetatableName());
    StdDequeValueBinding<Character::RagdollMsg>::registerBinding(L, "std::deque<Character::RagdollMsg>", Character_RagdollMsgBinding::getMetatableName());
    StdDequePrimitiveBinding<float>::registerBinding(L, "std::deque<float>", nullptr);
}

void LuaBindings::registerFitnessSelector(lua_State* L)
{
    FitnessSelectorBinding<CombatTechniqueData*>::registerBinding(L, "FitnessSelector<CombatTechniqueData*>", CombatTechniqueDataBinding::getMetatableName(), "std::map<float, CombatTechniqueData*>", "std::map<CombatTechniqueData*, float>");
    FitnessSelectorBinding<GameData*>::registerBinding(L, "FitnessSelector<GameData*>", GameDataBinding::getMetatableName(), "std::map<float, GameData*>", "std::map<GameData*, float>");
}

void LuaBindings::registerSTL(lua_State* L)
{
    registerStdSet(L);
    registerStdMap(L);
    registerStdDeque(L);
}

} // namespace KenshiLua
